#include <gtest/gtest.h>
#include <my_shared_lib.h>

TEST(MySharedLib, StandardOutput)
{
    testing::internal::CaptureStdout();
    SharedLibFunc("Hello");
    EXPECT_EQ("Hello my shared library\n", testing::internal::GetCapturedStdout());
}
