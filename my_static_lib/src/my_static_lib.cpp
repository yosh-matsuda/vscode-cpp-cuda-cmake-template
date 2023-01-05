#include "my_static_lib.h"
#include <boost/format.hpp>
#include <iostream>
#include <string>

void StaticLibFunc(const std::string& s) { std::cout << (boost::format("%1% my static library") % s) << std::endl; }
