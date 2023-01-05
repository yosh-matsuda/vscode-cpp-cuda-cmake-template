#include <gtest/gtest.h>
#include <my_header_lib.h>

TEST(MyHeaderLib, StandardOutput)
{
    testing::internal::CaptureStdout();
    HeaderLibFunc("Hello");
    EXPECT_EQ("Hello my header library\n", testing::internal::GetCapturedStdout());
}
