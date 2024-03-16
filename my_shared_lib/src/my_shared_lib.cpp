#include "my_shared_lib.h"
#include <fmt/core.h>
#include <string>

void SharedLibFunc(const std::string& s) { fmt::println("{} my shared library", s); }
