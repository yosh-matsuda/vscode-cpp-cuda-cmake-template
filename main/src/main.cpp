#include <my_header_lib.h>
#include <my_shared_lib.h>
#include <my_static_lib.h>

int main()
{
    HeaderLibFunc("Hello");
    StaticLibFunc("Hello");
    SharedLibFunc("Hello");
    return 0;
}
