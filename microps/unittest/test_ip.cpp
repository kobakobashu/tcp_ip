#include <gtest/gtest.h>
#include <arpa/inet.h>

extern "C"
{
    #include "../ip.h"
    #include "../net.h"
}

TEST(IpInitTest, CorrectInit){
    int result = ip_init();
    EXPECT_EQ(0, result);
}

TEST(IpAddrPtonTest, ValidAddresses) {
    ip_addr_t addr;

    EXPECT_EQ(ip_addr_pton("0.0.0.0", &addr), 0);
    EXPECT_EQ(addr, htonl(0x00000000));

    EXPECT_EQ(ip_addr_pton("1.0.0.0", &addr), 0);
    EXPECT_EQ(addr, htonl(0x01000000));

    EXPECT_EQ(ip_addr_pton("255.255.255.255", &addr), 0);
    EXPECT_EQ(addr, htonl(0xFFFFFFFF));

    EXPECT_EQ(ip_addr_pton("192.168.1.1", &addr), 0);
    EXPECT_EQ(addr, htonl(0xC0A80101));

    EXPECT_EQ(ip_addr_pton("10.0.0.1", &addr), 0);
    EXPECT_EQ(addr, htonl(0x0A000001));
}

TEST(IpAddrPtonTest, InvalidAddresses) {
    ip_addr_t addr;

    EXPECT_EQ(ip_addr_pton("192.168.1.256", &addr), -1);
    EXPECT_EQ(ip_addr_pton("192.168.1.-1", &addr), -1);
    EXPECT_EQ(ip_addr_pton("192.168.1", &addr), -1);
    EXPECT_EQ(ip_addr_pton("192.168.1.", &addr), -1);
    EXPECT_EQ(ip_addr_pton("192.168.1.1.", &addr), -1);
    EXPECT_EQ(ip_addr_pton("192.168.1.foo", &addr), -1);
    EXPECT_EQ(ip_addr_pton("", &addr), -1);
}

TEST(IPAddrNtopTest, ValidInput) {
    ip_addr_t n = htonl(0xC0000201);
    int size = 30;
    char buf[size];

    EXPECT_STREQ(ip_addr_ntop(n, buf, size), "192.0.2.1");
}
