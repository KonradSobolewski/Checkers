## @file calcpy/views.py
#  @brief calculation library interface to client

"""
calc library interface to client

export calculation results to client
"""
from calc import Game,Color


class GameList:
	games = {}


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


def userMove(params):
	x=int(params["x"])
	y=int(params["y"])

	

def loginUser():
	#login User in database
	return True	
