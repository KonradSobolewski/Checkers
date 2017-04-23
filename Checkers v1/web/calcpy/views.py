## @file calcpy/views.py
#  @brief calculation library interface to client

"""
calc library interface to client

export calculation results to client
"""
from calc import Game

def getNumber(params):
    """the calculation from C++ library"""
    a= Game()
    print(a.getX())
    return {
        "number" : a.getX()
    }


