#include "my_shared_lib.h"
#include <boost/format.hpp>
#include <iostream>
#include <string>

void SharedLibFunc(const std::string& s) { std::cout << (boost::format("%1% my shared library") % s) << std::endl; }
