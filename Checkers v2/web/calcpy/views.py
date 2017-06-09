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


game = Game()

def getToken(password, username):
	m = hashlib.md5()
	m.update(str(password)+str(username)+"arydn2")
	return m.hexdigest()


##Simple mutex class using a threading.lock() mechanism.
class security:
	lock=threading.Lock()


def loginUser(params):
	security.lock.acquire()
	token=None
	print("test")
	try:
		connection=psycopg2.connect(database=version.models.getDBName(), user=version.models.getDBUser(), password=version.models.getDBPassword(), host="127.0.0.1", port="5432")
		state=connection.cursor()
		#check if the database exist and if not create one
		state.execute("SELECT 1 FROM pg_tables WHERE schemaname='public' AND tablename='game_users'")
		rows=state.fetchall()
		if len(rows)==0:
			state.execute('''CREATE TABLE GAME_USERS
       			(ID INT PRIMARY KEY     NOT NULL,
       			LOGIN          	TEXT    NOT NULL,
       			PASSWORD_HASH   TEXT    NOT NULL);''')
			connection.commit()
		#compare username and password with the database
		state.execute("SELECT ID,LOGIN,PASSWORD_HASH FROM GAME_USERS")
		rows=state.fetchall()
		for row in rows:
			m = hashlib.md5()
			m.update(str(params["pass"]))
			in_password = m.hexdigest()
			#data correct
			if row[1]==params["username"] and row[2]==in_password:
				token = getToken(str(in_password), str(params["username"]))
	finally:
		connection.close()
		security.lock.release()
		return { "session-token": token }

def registerUser(params):
	valid = True
	print("test reg")
	security.lock.acquire()
	try:
		connection=psycopg2.connect(database=version.models.getDBName(), user=version.models.getDBUser(), password=version.models.getDBPassword(), host="127.0.0.1", port="5432")
		state=connection.cursor()
		#check if the database exist and if not create one
		state.execute("SELECT 1 FROM pg_tables WHERE schemaname='public' AND tablename='game_users'")
		rows=state.fetchall()
		if len(rows)==0:
			state.execute('''CREATE TABLE GAME_USERS
				(ID INT PRIMARY KEY    NOT NULL,
				LOGIN          TEXT    NOT NULL,
				PASSWORD_HASH  TEXT    NOT NULL
			);''')
			connection.commit()
		state.execute("SELECT ID,LOGIN FROM GAME_USERS")
		rows=state.fetchall()
		newId=1
		for row in rows:
			# User is already in the database
			if row[1]==params["username"]: 
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
			state.execute(("INSERT INTO GAME_USERS (ID,LOGIN,PASSWORD_HASH,WINS,LOSES) VALUES ({},\'{}\',\'{}\',0,0)").format(newId,params["username"],in_password))
			connection.commit()
	finally:
		connection.close()
		security.lock.release()
		#if registration successful log in user
		if valid:
			return loginUser(params)
		else:
			return { "session-token": None}



def makeMove(params):
	idSource = params['IDsource']
	idDest = params['IDdestination']
	print('send move: ' + idSource + " to " + idDest)
	return {
		'number' : params['IDsource'],
		'state' : 1
	}

def makeAIMove(params):
	
	#moveAI = game.getAI().makeMove(game.getState());
	#oldPos = moveAI.getPiece().getPosition();
	#game.executeMove(moveAI,game.getAI());
	#newPos = moveAI.getPos();
	return {
		'source' : 1,
		'destination' : 1
	}

def cppCom(params):
	print('Cpp communication...')
	print(game.getX())	
	return {
		"number" : game.getX()
	}

	
