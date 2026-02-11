#include <my_header_lib.hpp>
#include <my_shared_lib.hpp>
#include <my_static_lib.hpp>

int main()
{
    HeaderLibFunc("Hello");
    StaticLibFunc("Hello");
    SharedLibFunc("Hello");
    return 0;
}
