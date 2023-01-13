#pragma once
#include <boost/format.hpp>
#include <iostream>

template <typename T>
void HeaderLibFunc(T s)
{
    std::cout << (boost::format("%1% my header library") % s) << std::endl;
}
