/**
 * \file calcpy.cpp
 * \brief the Python interface for C++ calculation library
 */


#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "Game.hpp"
#include "Move.hpp"
#include "Player.hpp"
#include "AI.hpp"
#include "Piece.hpp"
#include "State.hpp"
#include "Declarations.hpp"
#include "Human.hpp"

using namespace boost::python;

/**
 * Python wrapper using Boost.Python
 */
BOOST_PYTHON_MODULE( calc )
{

    boost::python::enum_<Color>("Color")
	.value( "BlACK", BLACK )
	.value( "WHITE", WHITE )
	;

    boost::python::enum_<Element>("Element")
	.value( "WHITE_BLANK", WHITE_BLANK )
	.value( "BLACK_BLANK", BLACK_BLANK )
	.value( "WHITE_PIECE", WHITE_PIECE )
	.value( "BLACK_PIECE", BLACK_PIECE )
	.value( "OUT_OF_BOARD", OUT_OF_BOARD )
	;
    
    boost::python::class_<State,std::shared_ptr<State>>("State",boost::python::init<>())
	.def( "getBoard", &State::getBoard)
	.def( "changeBoard", &State::changeBoard)
		;

    boost::python::class_<Piece,std::shared_ptr<Piece>>("Piece",boost::python::init<int , int, Element , bool , bool>())
	.def( "getPosition", &Piece::getPosition)
	.def( "setPosition", &Piece::setPosition)
	.def( "getColor", &Piece::getColor)
		;


    boost::python::class_<Move,std::shared_ptr<Move>>("Move",boost::python::init<int, bool, std::shared_ptr<Piece>, bool, int>())
	.def("getPos", &Move::getPos)
	.def("getPiece", &Move::getPiece)
	.def("isHumanMove", &Move::isHumanMove)
	.def("isHit", &Move::isHit)
	.def("getHitPos", &Move::getHitPos)
		;

    boost::python::class_<Player,std::shared_ptr<Player>>("Player",boost::python::init<bool,Color>())
	.def("getColor", &Player::getColor)
	.def("isActive", &Player::isActive)
	.def("isWinner", &Player::isWinner)
	.def("getPieces", &Player::getPieces)
	.def("getPieceById", &Player::getPieceById)
	.def("getPieceByPosition", &Player::getPieceByPosition)
	.def("hitPiece", &Player::hitPiece)
		;
    boost::python::class_<AI,boost::python::bases<Player>,std::shared_ptr<AI>>("AI",boost::python::init<bool,Color>())
	.def( "makeMove", &AI::makeMove)
		;	

    boost::python::class_<Human,boost::python::bases<Player>,std::shared_ptr<Human>>("Human",boost::python::init<bool,Color>())
		;


    boost::python::class_<Game,std::shared_ptr<Game>>("Game",boost::python::init<>())
        .def("getX", &Game::getX)
	.def("isHumanTurn", &Game::isHumanTurn)
	.def("checkMove", &Game::checkMove)
	.def("executeMove", &Game::executeMove)
	.def("checkVictory", &Game::checkVictory)
	.def("getState", &Game::getState)
	.def("getAI", &Game::getAI)
	.def("getHuman", &Game::getHuman)
        ;

   
}
