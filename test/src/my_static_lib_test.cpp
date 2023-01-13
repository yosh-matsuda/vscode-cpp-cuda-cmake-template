#include <gtest/gtest.h>
#include <my_static_lib.h>

TEST(MyStaticLib, StandardOutput)
{
    testing::internal::CaptureStdout();
    StaticLibFunc("Hello");
    EXPECT_EQ("Hello my static library\n", testing::internal::GetCapturedStdout());
}
