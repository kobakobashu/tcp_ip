#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
    #include "../arp.h"
}

TEST(ArpInitTest, Success) {
    int result = arp_init();
    EXPECT_EQ(result, 0);
}

TEST(ArpInitTest, Failure) {
    int result = arp_init();
    EXPECT_EQ(result, -1);
}