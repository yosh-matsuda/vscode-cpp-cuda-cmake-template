#pragma once
#include <fmt/core.h>

template <typename T>
void HeaderLibFunc(T s)
{
    fmt::println("{} my header library", s);
}
