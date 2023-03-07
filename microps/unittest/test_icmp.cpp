#include <gtest/gtest.h>

extern "C"
{
    #include "../icmp.h"
}

TEST(IcmpInitTest, Success) {
    int result = icmp_init();
    EXPECT_EQ(result, 0);
}

TEST(IcmpInitTest, Failure) {
    int result = icmp_init();
    EXPECT_EQ(result, -1);
}