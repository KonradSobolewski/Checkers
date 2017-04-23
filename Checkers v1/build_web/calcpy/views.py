## @file calcpy/views.py
#  @brief calculation library interface to client

"""
calc library interface to client

export calculation results to client
"""
from calc import Game,Color


class GameList:
	games = {}

def getNumber(params):
	a= Game()	
	print(a.getX())
	print(params)
	return {
		"number" : a.getX()
	}

def userMove(params):
	x=int(params["x"])
	y=int(params["y"])

	

def loginUser():
	#login User in database
	return True	
