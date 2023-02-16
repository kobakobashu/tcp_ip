#include <gtest/gtest.h>

extern "C"
{
    #include "../ip.h"
    #include "../net.h"
}

TEST(IpInitTest, CorrectInit){
    int result = ip_init();
    EXPECT_EQ(0, result);
}