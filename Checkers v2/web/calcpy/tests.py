## @file calcpy/tests.py
#  @brief c++ calculation library Python API unit testing

import django.test
import calc
import views
import time
import psycopg2
import version.models
import hashlib

class CalcPyLibraryTestCase(django.test.TestCase):
    """integration test, call C++ library interface from Python"""
    
    def test01playerPositionTest(self):
	game = calc.Game()
	playerPiece = game.getHuman().getPieceById(1);
	piecePos = playerPiece.getPosition()
	self.assertEqual(piecePos, 0)
    
    def test02AIpositionTest(self):
	game = calc.Game()
	aiPiece = game.getAI().getPieceById(1);
	piecePos = aiPiece.getPosition()
	self.assertEqual(piecePos, 41)

    def test03moveTest(self):
	game = calc.Game()
	playerPiece = game.getHuman().getPieceById(9)
	playerMove = calc.Move(25, True, playerPiece, False, 0) 
	isRight = game.checkMove(playerMove) 
	self.assertEqual(isRight, True)
	playerMove = calc.Move(12, True, playerPiece, False, 0)
	isRight = game.checkMove(playerMove) 
	self.assertEqual(isRight, False)

    def test04aiMoveTest(self):
	game = calc.Game()
	aiMove = game.getAI().makeMove(game.getState())
	isRight = game.checkMove(aiMove) 
	self.assertEqual(isRight, True)
   
    def test05executeMoveTest(self):
	game = calc.Game()
	playerPiece = game.getHuman().getPieceById(9)
	playerMove = calc.Move(25, True, playerPiece, False, 0) 
	game.executeMove(playerMove, game.getHuman())
	newPos = playerPiece.getPosition()
	self.assertEqual(newPos, 25)

    def test06PieceHitting(self):
	game = calc.Game()
	playerPiece = game.getHuman().getPieceById(9)
	aiPiece = game.getAI().getPieceById(2)
	playerMove = calc.Move(25, True, playerPiece, False, 0)
	game.executeMove(playerMove, game.getHuman())
	aiMove = calc.Move(34, False, aiPiece, False, 0)
	game.executeMove(aiMove, game.getAI())
	playerMove = calc.Move(43, True, playerPiece, True, 34)
	game.executeMove(playerMove, game.getHuman())
	numberOfAIPieces = game.getAI().getPiecesNumber()
	self.assertEqual(numberOfAIPieces, 11)
	

class CalcPyViewTestCase(django.test.TestCase):

    def test01registerUser(self):
	params={"name":"test1","pass":"test1"}
	views.registerUser(params)
	conn=psycopg2.connect(database=version.models.getDBName(), user=version.models.getDBUser(), password=version.models.getDBPassword(), host="127.0.0.1", port="5432")
	cur=conn.cursor()
	cur.execute("SELECT PASSWORD_HASH FROM game_users WHERE LOGIN='test1'")
	rows=cur.fetchall()
	self.assertNotEqual(len(rows),0)
	m = hashlib.md5()
	m.update(str(params["pass"]))
	pass1 = m.hexdigest()
	for row in rows:
		self.assertEqual(row[0],pass1)
	conn.commit()
	conn.close()
	##loginUser and getToken test

	

    def test02loginUser03getToken(self):
	params={"name":"test1","pass":"test1"}
	token1=views.loginUser(params)['session-token']
	m = hashlib.md5()
	m.update(str(params["pass"]))
	pass1 = m.hexdigest()
	token2=views.getToken(pass1,params["name"])
	self.assertEqual(token1,token2)






