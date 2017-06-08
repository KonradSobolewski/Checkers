## @file calcpy/views.py
#  @brief calculation library interface to client

"""
calc library interface to client

export calculation results to client
"""
from calc import *
import psycopg2
import version.models
import threading
import datetime as dt
import hashlib


class GameList:
	games = {}

def getToken(password, name):
	m = hashlib.md5()
	m.update(str(password)+str(name)+"arydn2")
	return m.hexdigest()


##Simple mutex class using a threading.lock() mechanism.
class L:
	l=threading.Lock()


def loginUser(params):
	L.l.acquire()
	token=None
	print("test")
	try:
		conn=psycopg2.connect(database=version.models.getDBName(), user=version.models.getDBUser(), password=version.models.getDBPassword(), host="127.0.0.1", port="5432")
		cur=conn.cursor()
		#check if the database exist and if not create one
		cur.execute("SELECT 1 FROM pg_tables WHERE schemaname='public' AND tablename='game_users'")
		rows=cur.fetchall()
		if len(rows)==0:
			cur.execute('''CREATE TABLE GAME_USERS
       			(ID INT PRIMARY KEY     NOT NULL,
       			LOGIN          	TEXT    NOT NULL,
       			PASSWORD_HASH   TEXT    NOT NULL);''')
			conn.commit()
		#compare name and password with the database
		cur.execute("SELECT ID,LOGIN,PASSWORD_HASH FROM GAME_USERS")
		rows=cur.fetchall()
		for row in rows:
			m = hashlib.md5()
			m.update(str(params["pass"]))
			in_password = m.hexdigest()
			#data correct
			if row[1]==params["name"] and row[2]==in_password:
				token = getToken(str(in_password), str(params["name"]))
	finally:
		conn.close()
		L.l.release()
		return { "session-token": token }

def registerUser(params):
	valid = True
	print("test")
	L.l.acquire()
	try:
		conn=psycopg2.connect(database=version.models.getDBName(), user=version.models.getDBUser(), password=version.models.getDBPassword(), host="127.0.0.1", port="5432")
		cur=conn.cursor()
		#check if the database exist and if not create one
		cur.execute("SELECT 1 FROM pg_tables WHERE schemaname='public' AND tablename='game_users'")
		rows=cur.fetchall()
		if len(rows)==0:
			cur.execute('''CREATE TABLE GAME_USERS
				(ID INT PRIMARY KEY    NOT NULL,
				LOGIN          TEXT    NOT NULL,
				PASSWORD_HASH  TEXT    NOT NULL
			);''')
			conn.commit()
		cur.execute("SELECT ID,LOGIN FROM GAME_USERS")
		rows=cur.fetchall()
		newId=1
		for row in rows:
			# User is already in the database
			if row[1]==params["name"]: 
				valid = False
				raise
			#generate new id for a new player
			elif row[0]>=newId:
				newId=row[0]+1
		if valid:
			#put new player into database
			m = hashlib.md5()
			m.update(str(params["pass"]))
			in_password = m.hexdigest()
			cur.execute(("INSERT INTO GAME_USERS (ID,LOGIN,PASSWORD_HASH,WINS,LOSES) VALUES ({},\'{}\',\'{}\',0,0)").format(newId,params["name"],in_password))
			conn.commit()
	finally:
		conn.close()
		L.l.release()
		#if registration successful log in user
		if valid:
			return loginUser(params)
		else:
			return { "session-token": None}



def printID(params):
	print("lol")
	idSource = params['IDsource']
	idDest = params['IDdestination']
	
	print('send move: ' + idSource + " to " + idDest)
	return {
		"number" : params['IDsource']
	}

def cppCom(params):
	print('Cpp communication...')
	game = Game()
	print(game.getX())	
	return {
		"number" : game.getX()
	}

	
