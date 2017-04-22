## @file calcpy/views.py
#  @brief calculation library interface to client

"""
calc library interface to client
export calculation results to client
"""
from Game import Game

def getNumber(params):
    a=Game()
    print (a.getX())
    return {
        "number" : a.getX()
    }




	
