#include <gtest/gtest.h>

extern "C"
{
    #include "../icmp.h"
}

typedef int (*MockIpProtocolRegisterFn)(uint8_t type, void *handler);

MockIpProtocolRegisterFn mock_ip_protocol_register = nullptr;

int mock_ip_protocol_register_success(uint8_t type, void *handler) {
    return 0;
}

int mock_ip_protocol_register_failure(uint8_t type, void *handler) {
    return -1;
}

TEST(IcmpInitTest, Success) {
    mock_ip_protocol_register = mock_ip_protocol_register_success;
    int result = icmp_init();
    EXPECT_EQ(result, 0);
}

TEST(IcmpInitTest, Failure) {
    mock_ip_protocol_register = mock_ip_protocol_register_failure;
    int result = icmp_init();
    EXPECT_EQ(result, -1);
}