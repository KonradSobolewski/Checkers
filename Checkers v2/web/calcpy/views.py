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

##globalny obiekt gry
game = Game()


##zwraca token dla danego gracza
#@password - haslo danego gracza
#@username - login danego gracza
def getToken(password, username):
	m = hashlib.md5()
	m.update(str(password)+str(username)+"asdnzn1")
	return m.hexdigest()


##prosta klasa typu mutex
class security:
	lock=threading.Lock()


## logowanie uzytkownika do bazy danych
#@ params - slownik odebrany z js zawierajcy haslo i login
def loginUser(params):
	security.lock.acquire()
	token=None
	print("test log")
	try:
		connection=psycopg2.connect(database=version.models.getDBName(), user=version.models.getDBUser(), password=version.models.getDBPassword(), host="127.0.0.1", port="5432")
		state=connection.cursor()
		#sprawdzamy czy baza danych istnieje jesli nie to tworzymy
		state.execute("SELECT 1 FROM pg_tables WHERE schemaname='public' AND tablename='game_users'")
		rows=state.fetchall()
		if len(rows)==0:
			state.execute('''CREATE TABLE GAME_USERS
       			(ID INT PRIMARY KEY     NOT NULL,
       			LOGIN          	TEXT    NOT NULL,
       			PASSWORD_HASH   TEXT    NOT NULL);''')
			connection.commit()
		#porownanie loginu i hasla z wartosciami z bazy
		state.execute("SELECT ID,LOGIN,PASSWORD_HASH FROM GAME_USERS")
		rows=state.fetchall()
		for row in rows:
			m = hashlib.md5()
			m.update(str(params["pass"]))
			in_password = m.hexdigest()
			#poprawne dane
			if row[1]==params["username"] and row[2]==in_password:
				token = getToken(str(in_password), str(params["username"]))
	finally:
		connection.close()
		security.lock.release()
		return { "session-token": token }

## rejestracja uzytkownika do bazy danych
#@ params - slownik odebrany z js zawierajcy haslo i login
def registerUser(params):
	valid = True
	print("test reg")
	security.lock.acquire()
	try:
		connection=psycopg2.connect(database=version.models.getDBName(), user=version.models.getDBUser(), password=version.models.getDBPassword(), host="127.0.0.1", port="5432")
		state=connection.cursor()
		#sprawdzamy czy baza danych istnieje jesli nie to tworzymy
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
			# jesli user juz istnieje
			if row[1]==params["username"]: 
				valid = False
				raise
			#tworzymy nowe id dla gracza
			elif row[0]>=newId:
				newId=row[0]+1
		if valid:
			#dolacz gracza do bazy danych 
			m = hashlib.md5()
			m.update(str(params["pass"]))
			in_password = m.hexdigest()
			state.execute(("INSERT INTO GAME_USERS (ID,LOGIN,PASSWORD_HASH,WINS,LOSES) VALUES ({},\'{}\',\'{}\',0,0)").format(newId,params["username"],in_password))
			connection.commit()
	finally:
		connection.close()
		security.lock.release()
		#jesli udalo sie zarejestrowac to zalogujemy sie
		if valid:
			return loginUser(params)
		else:
			return { "session-token": None}


## metoda wykonuje ruch gracza
#@ params - slownik zawierajacy pozycje z ktorej do ktorej sie chcemy ruszyc
def makeMove(params):
	idSource = int(params['IDsource'])
	idDest = int(params['IDdestination'])
        distance = abs(idSource - idDest)
	isLong = False
	probableHitPos = -1
	if distance >=14 :
		isLong = True
		probableHitPos = (idDest - idSource)/2 + idSource
        playerPiece = game.getHuman().getPieceByPosition(idSource)
	playerMove = Move(idDest, True, playerPiece, isLong, probableHitPos)
	allowToMove = 0
	if bool(game.checkMove(playerMove)):
		luck = game.executeMove(playerMove,game.getHuman());
		allowToMove = 1
	return {
		'number' : params['IDsource'],
		'state' : allowToMove,
		'isHit' : isLong,
		'hitPos' : probableHitPos
	}
	
##metoda wykonuje ruch AI
def makeAIMove(params):
	moveAI = game.getAI().makeMove(game.getState())
	oldPos = str(moveAI.getPiece().getPosition())
	newPos = str(moveAI.getPos())
	isHit = bool(moveAI.isHit())
 	hitPos = str(moveAI.getHitPos())	
	luck = game.executeMove(moveAI,game.getAI());
	return {
			'src' : oldPos,
			'dest' : newPos,
			'isHit': isHit,
			'hitPos' : hitPos
	}

## funkcja testujaca 
def cppCom(params):
	print('Cpp communication...')
	print(game.getX())	
	return {
		"number" : game.getX()
	}

	
