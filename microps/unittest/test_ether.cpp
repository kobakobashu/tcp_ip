

#include <gtest/gtest.h>
#include <gmock/gmock.h>

extern "C"
{
    #include "../ether.h"
}

TEST(EtherAddrPtonTest, NullPointerTest) {
    uint8_t n[ETHER_ADDR_LEN];
    const char *p = "11:22:33:44:55:66";
    EXPECT_EQ(ether_addr_pton(p, nullptr), -1); // Null pointer test
    EXPECT_EQ(ether_addr_pton(nullptr, n), -1); // Null pointer test
}

TEST(EtherAddrPtonTest, InvalidInputTest) {
    uint8_t n[ETHER_ADDR_LEN];
    const char *p = "11:22:33:44:55:GG"; // Invalid character
    EXPECT_EQ(ether_addr_pton(p, n), -1);
    p = "11:22:33:44:55:66:77"; // Too many octets
    EXPECT_EQ(ether_addr_pton(p, n), -1);
    p = "11:22:33:44:55"; // Too few octets
    EXPECT_EQ(ether_addr_pton(p, n), -1);
    p = "11:22:33:44:55:"; // Trailing colon
    EXPECT_EQ(ether_addr_pton(p, n), -1);
}

TEST(EtherAddrPtonTest, ValidInputTest) {
    uint8_t n[ETHER_ADDR_LEN];
    const char *p = "11:22:33:44:55:66";
    EXPECT_EQ(ether_addr_pton(p, n), 0);
    EXPECT_EQ(n[0], 0x11);
    EXPECT_EQ(n[1], 0x22);
    EXPECT_EQ(n[2], 0x33);
    EXPECT_EQ(n[3], 0x44);
    EXPECT_EQ(n[4], 0x55);
    EXPECT_EQ(n[5], 0x66);
}