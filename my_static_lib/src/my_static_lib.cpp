#include "my_static_lib.hpp"
#include <fmt/core.h>
#include <string>

void StaticLibFunc(const std::string& s) { fmt::println("{} my static library", s); }
