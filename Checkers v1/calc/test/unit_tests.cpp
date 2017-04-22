/**
** Unit Testing for Checkers Game. 
** Author: Walczakp007 
*/
#define BOOST_TEST_DYN_LINK
#define BOOST_TEST_MODULE Suites
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "../src/Game.hpp"

using namespace boost::unit_test;

BOOST_AUTO_TEST_SUITE( PieceTest )

BOOST_AUTO_TEST_CASE( constructorTest )
{
    auto piece = std::make_shared<Piece>(5, 5, BLACK, false, false);
    BOOST_CHECK_EQUAL(piece->getX(), 5);
    BOOST_CHECK_EQUAL(piece->getY(), 5);
    BOOST_CHECK_EQUAL(piece->getColor(), BLACK);
    BOOST_CHECK_EQUAL(piece->getWhoseMove(), false);
    BOOST_CHECK_EQUAL(piece->isUpgraded(), false);
}

BOOST_AUTO_TEST_CASE( settersTest )
{
 
   auto piece = std::make_shared<Piece>(5, 5, BLACK, false, false);
    piece->setPosition(2, 2);
    piece->setWhosePiece(true);
    piece->upgrade();
    BOOST_CHECK_EQUAL(piece->getX(), 2);
    BOOST_CHECK_EQUAL(piece->getY(), 2);
    BOOST_CHECK_EQUAL(piece->getColor(), BLACK);
    BOOST_CHECK_EQUAL(piece->getWhoseMove(), true);
    BOOST_CHECK_EQUAL(piece->isUpgraded(), true);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( MoveTest )

BOOST_AUTO_TEST_CASE( constructorTest )
{
    auto piece = std::make_shared<Piece>(5, 5, BLACK, false, false);
    auto move = std::make_shared<Move>(6, 6, false, piece);
    BOOST_CHECK_EQUAL(move->getX(), 6);
    BOOST_CHECK_EQUAL(move->getY(), 6);
    BOOST_CHECK_EQUAL(move->isHumanMove(), false); 
}

BOOST_AUTO_TEST_CASE( settersTest )
{
    auto piece = std::make_shared<Piece>(5, 5, BLACK, false, false);
    auto move = std::make_shared<Move>(6, 6, false, piece);
    move->setX(2);
    move->setY(2);
    move->setWhoseMove(true);
    BOOST_CHECK_EQUAL(move->getX(), 2);
    BOOST_CHECK_EQUAL(move->getY(), 2);
    BOOST_CHECK_EQUAL(move->isHumanMove(), true); 
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( PlayerTest )

BOOST_AUTO_TEST_CASE( constructorTest )
{   
    auto player = std::make_shared<Player>(false, WHITE);
    for(int i = 0; i < 5; i++) 
    	player->addPiece(std::make_shared<Piece>(i, i+1, BLACK, false, false));
    BOOST_CHECK_EQUAL(player->getColor(), WHITE);
    BOOST_CHECK_EQUAL(player->isActive(), false);
    BOOST_CHECK_EQUAL(player->isWinner(), false);
}

BOOST_AUTO_TEST_CASE( settersTest )
{
    auto player = std::make_shared<Player>(false, BLACK);
    for(int i = 0; i < 5; i++) 
    	player->addPiece(std::make_shared<Piece>(i, i+1, WHITE, false, false));
    player->setActive(true);
    player->setWinner(true);
    BOOST_CHECK_EQUAL(player->isActive(), true);
    BOOST_CHECK_EQUAL(player->isWinner(), true);
    BOOST_CHECK_EQUAL(player->getPiecesNumber(), 5);
}

BOOST_AUTO_TEST_SUITE_END()


BOOST_AUTO_TEST_SUITE( StateTest )

BOOST_AUTO_TEST_CASE( constructorTest )
{   
   auto state = std::make_shared<State>();
   BOOST_REQUIRE_EQUAL( state->getBoardSize(), BOARD_SIZE*BOARD_SIZE); 
}

BOOST_AUTO_TEST_CASE( possibleMovesTest )
{
    auto piece = std::make_shared<Piece>(5, 5, BLACK, false, false);
    auto move = std::make_shared<Move>(6, 6, false, piece);
    std::vector<std::vector<bool>> possibleMoves;
    possibleMoves.push_back( std::vector<bool>() );
    for (int j = 0; j < BOARD_SIZE; ++j)
	possibleMoves[j].push_back(j%2);

    auto state = std::make_shared<State>();
    Board statePossibleMoves = state->getPossibleMoves(move);
    for (int j = 0; j < BOARD_SIZE; ++j)
    	BOOST_CHECK_EQUAL_COLLECTIONS(statePossibleMoves[j].begin(), statePossibleMoves[j].end(), possibleMoves[j].begin(), possibleMoves[j].end()); 
}
BOOST_AUTO_TEST_SUITE_END()
