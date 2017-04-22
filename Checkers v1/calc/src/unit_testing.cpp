/**
** Unit Testing for Checkers Game. 
** Author: Walczakp007 
*/
#include <boost/test/included/unit_test.hpp>
#include <iostream>
#include "Game.hpp"

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

