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
    
    piece = player->getPieceById(9);
    statePossibleMoves = state->getPossibleMoves(piece);
    std::vector<int> possibleMoves2 = {25};
    BOOST_CHECK_EQUAL_COLLECTIONS(statePossibleMoves.begin(), statePossibleMoves.end(), possibleMoves2.begin(), possibleMoves2.end());

    piece = player->getPieceById(11);
    std::vector<int> possibleMoves3 = {29, 27};
    statePossibleMoves = state->getPossibleMoves(piece);
    //BOOST_CHECK_EQUAL_COLLECTIONS(statePossibleMoves.begin(), statePossibleMoves.end(), possibleMoves3.begin(), possibleMoves3.end());

    auto player2 = std::make_shared<Player>(false, BLACK);
    player2->createPieces();
    piece = player2->getPieceById(8);
    std::vector<int> possibleMoves4 = {};
    statePossibleMoves = state->getPossibleMoves(piece);
    BOOST_CHECK_EQUAL_COLLECTIONS(statePossibleMoves.begin(), statePossibleMoves.end(), possibleMoves4.begin(), possibleMoves4.end());

    piece = player2->getPieceById(1);
    std::vector<int> possibleMoves5 = {32, 34};
    statePossibleMoves = state->getPossibleMoves(piece);
    BOOST_CHECK_EQUAL_COLLECTIONS(statePossibleMoves.begin(), statePossibleMoves.end(), possibleMoves5.begin(), possibleMoves5.end());

}

BOOST_AUTO_TEST_CASE( checkMovesTest )
{
    
    auto game = std::make_shared<Game>();
    auto piece = game->getHuman()->getPieceById(9);
    auto move = std::make_shared<Move>(25, true, piece, false, 0); 
    BOOST_CHECK_EQUAL(game->checkMove(move), true);
    move = std::make_shared<Move>(12, true, piece, false, 0);
    BOOST_CHECK_EQUAL(game->checkMove(move), false);
    //auto piece = game->getHuman()->getPieceById(9);
    //auto move = std::make_shared<Move>(25, true, piece, false, 0);   
// BOOST_CHECK_EQUAL(game->checkMove(move), false);
}


BOOST_AUTO_TEST_SUITE_END()



BOOST_AUTO_TEST_SUITE( executeMove )

BOOST_AUTO_TEST_CASE( checkMovesTest )
{
    
    auto game = std::make_shared<Game>();
    auto piece = game->getHuman()->getPieceById(9);
    auto aipiece = game->getAI()->getPieceById(2);
    auto move = std::make_shared<Move>(25, true, piece, false, 0);
    BOOST_CHECK_EQUAL(game->checkMove(move), true);
    game->executeMove(move, game->getHuman());
    BOOST_CHECK_EQUAL(game->getHuman()->getPieceById(9)->getPosition(), 25);
    move = std::make_shared<Move>(34, true, piece, false, 0); 
    BOOST_CHECK_EQUAL(game->checkMove(move), true);
    game->executeMove(move, game->getHuman());
    BOOST_CHECK_EQUAL(game->getHuman()->getPieceById(9)->getPosition(), 34);
    move = std::make_shared<Move>(25, false, aipiece, true, 34);
    BOOST_CHECK_EQUAL(game->checkMove(move), true);
    game->executeMove(move, game->getAI());
    BOOST_CHECK_EQUAL(game->getHuman()->getPiecesNumber(), 11);

}

BOOST_AUTO_TEST_SUITE_END()

BOOST_AUTO_TEST_SUITE( aiAlgorithm )

BOOST_AUTO_TEST_CASE( possibleMove )
{
    
    auto game = std::make_shared<Game>();
    auto ai = game->getAI();
    auto move = ai->makeMove(game->getState());
    BOOST_CHECK_EQUAL(game->checkMove(move), true);

}


BOOST_AUTO_TEST_CASE( simulateTwoAIs )
{
    
    auto game = std::make_shared<Game>();
    auto ai = game->getAI();
    ai->hitPiece(41);
    ai->hitPiece(43);
    ai->hitPiece(45);
    ai->hitPiece(48);
    ai->hitPiece(50);
    ai->hitPiece(52);
    ai->hitPiece(54);
    ai->hitPiece(57);
    ai->hitPiece(59);
    ai->hitPiece(61);
    ai->hitPiece(63);   
    BOOST_CHECK_EQUAL(ai->getPiecesNumber(), 1);
    BOOST_REQUIRE(ai->getPiecesNumber() == 1);
    auto player = game->getHuman();
    auto playerPiece = player->getPieceById(11);
    auto move = std::make_shared<Move>(29, true, playerPiece, false, 0);
    game->executeMove(move, game->getHuman());
    BOOST_REQUIRE(playerPiece->getPosition() == 29);
    move = std::make_shared<Move>(38, true, playerPiece, false, 0);
    BOOST_CHECK_EQUAL(game->checkMove(move), true);
    game->executeMove(move, game->getHuman()); 
    BOOST_REQUIRE(playerPiece->getPosition() == 38);
    std::vector<int> lol = {29};
    std::vector<int> lol2 = game->getState()->getPossibleMoves(ai->getPieceById(4));
    BOOST_CHECK_EQUAL_COLLECTIONS(lol.begin(), lol.end(), lol2.begin(), lol2.end());

    auto aiMove = ai->makeMove(game->getState());
    BOOST_CHECK_EQUAL(aiMove->getPos(), 29);
    BOOST_CHECK_EQUAL(aiMove->getPiece()->getID(), 4);
    BOOST_CHECK_EQUAL(aiMove->isHit(), true);
    BOOST_CHECK_EQUAL(aiMove->getHitPos(), 38);
    BOOST_CHECK_EQUAL(game->checkMove(aiMove), true);
    game->executeMove(aiMove, ai);
    BOOST_CHECK_EQUAL(ai->getPieceById(4)->getPosition(), 29);
    BOOST_CHECK_EQUAL(player->getPiecesNumber(), 11);
   
}

BOOST_AUTO_TEST_SUITE_END()


