/**
** Unit Testing for Checkers Game. 
** Author: Walczakp007 
*/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "../src/Game.hpp"
#include "../src/Player.cpp"
#include "../src/State.cpp"
#include "../src/Piece.cpp"
#include "../src/Declarations.hpp"


using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( PieceTest )

BOOST_AUTO_TEST_CASE( constructorTest )
{
    auto piece = std::make_shared<Piece>(5, 5, Element::BLACK_PIECE, false, false);
    BOOST_CHECK_EQUAL(piece->getPosition(), 5);
    BOOST_CHECK_EQUAL(piece->getID(), 5);
    BOOST_CHECK_EQUAL(piece->getWhoseMove(), false);
    BOOST_CHECK_EQUAL(piece->isUpgraded(), false);
}



BOOST_AUTO_TEST_CASE( settersTest )
{
 
   auto piece = std::make_shared<Piece>(5, 5, Element::BLACK_PIECE, false, false);
    piece->setPosition(2);
    piece->setWhosePiece(true);
    piece->upgrade();
    BOOST_CHECK_EQUAL(piece->getPosition(), 2);
 //   BOOST_CHECK_EQUAL(piece->getColor(), Element::BLACK_PIECE);
    BOOST_CHECK_EQUAL(piece->getWhoseMove(), true);
    BOOST_CHECK_EQUAL(piece->isUpgraded(), true);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( MoveTest )

BOOST_AUTO_TEST_CASE( constructorTest )
{
    auto piece = std::make_shared<Piece>(5, 5, Element::BLACK_PIECE, false, false);
    auto move = std::make_shared<Move>(6, false, piece,false,1);
    BOOST_CHECK_EQUAL(move->getPos(), 6);
    BOOST_CHECK_EQUAL(move->isHit(), false);
    BOOST_CHECK_EQUAL(move->isHumanMove(), false); 
    BOOST_CHECK_EQUAL(move->getHitPos(), 1); 
}

BOOST_AUTO_TEST_CASE( settersTest )
{
    auto piece = std::make_shared<Piece>(5, 5, Element::BLACK_PIECE, false, false);
    auto move = std::make_shared<Move>(6, false, piece,false,1);
    move->setPos(2);
    move->setWhoseMove(true);
    BOOST_CHECK_EQUAL(move->getPos(), 2);
    BOOST_CHECK_EQUAL(move->isHumanMove(), true); 
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( PlayerTest )

BOOST_AUTO_TEST_CASE( constructorTest )
{   
    auto player = std::make_shared<Player>(false, WHITE);
    for(int i = 0; i < 5; i++) 
    	player->addPiece(std::make_shared<Piece>(i+1, i, Element::WHITE_PIECE, false, false));
    BOOST_CHECK_EQUAL(player->getColor(), WHITE);
    BOOST_CHECK_EQUAL(player->isActive(), false);
    BOOST_CHECK_EQUAL(player->isWinner(), false);
    player->hitPiece(1);
    player->createPieces();
    BOOST_CHECK_EQUAL(player->getPieces().size(), 16);
}

BOOST_AUTO_TEST_CASE( settersTest )
{
    auto player = std::make_shared<Player>(false, BLACK);
    for(int i = 0; i < 5; i++) 
    	player->addPiece(std::make_shared<Piece>(i+1, i, Element::BLACK_PIECE, false, false));
    player->setActive(true);
    player->setWinner(true);
    BOOST_CHECK_EQUAL(player->isActive(), true);
    BOOST_CHECK_EQUAL(player->isWinner(), true);
    BOOST_CHECK_EQUAL(player->getPiecesNumber(), 5);
    player->hitPiece(5);
    BOOST_CHECK_EQUAL(player->getPieces().size(), 4);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( MovesTest )

BOOST_AUTO_TEST_CASE( possibleMovesTest )
{
    
    auto player = std::make_shared<Player>(false, WHITE);
    player->createPieces();
    auto state = std::make_shared<State>();
    auto piece = player->getPieceById(1);
    BOOST_CHECK_EQUAL(piece->getPosition(), 0);
    std::vector<int> statePossibleMoves = state->getPossibleMoves(piece);
    std::vector<int> possibleMoves = {};
    BOOST_CHECK_EQUAL_COLLECTIONS(statePossibleMoves.begin(), statePossibleMoves.end(), possibleMoves.begin(), possibleMoves.end());
    for (int j = 0; j < BOARD_SIZE; ++j)
    	;//BOOST_CHECK_EQUAL_COLLECTIONS(statePossibleMoves[j].begin(), statePossibleMoves[j].end(), possibleMoves[j].begin(), possibleMoves[j].end()); 
}
BOOST_AUTO_TEST_SUITE_END()
