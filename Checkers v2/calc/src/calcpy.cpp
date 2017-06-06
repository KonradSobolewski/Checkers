/**
 * \file calcpy.cpp
 * \brief the Python interface for C++ calculation library
 */


#include <boost/python.hpp>
#include <boost/python/suite/indexing/vector_indexing_suite.hpp>

#include "Game.hpp"

using namespace boost::python;

/**
 * Python wrapper using Boost.Python
 */
BOOST_PYTHON_MODULE( calc )
{

    class_<Calc,std::shared_ptr<Game>>("Game")
        .def( "getX", &Calc::getX)
        ;
}
