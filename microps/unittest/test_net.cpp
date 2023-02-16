#include <gtest/gtest.h>

extern "C"
{
    #include "../net.h"
}

TEST(NetDeviceRegisterTest, RegisterDevice) {
    struct net_device *dev;
    
    struct net_device *dev_1;
    struct net_device *dev_2;

    dev_1 = net_device_alloc();
    EXPECT_TRUE(dev_1);

    dev_2 = net_device_alloc();
    EXPECT_TRUE(dev_2);

    int result_1 = net_device_register(dev_1);
    int result_2 = net_device_register(dev_2);

    EXPECT_EQ(result_1, 0);
    EXPECT_EQ(result_2, 0);

    EXPECT_EQ(dev_2->index, 1);
    EXPECT_EQ(dev_2->next, dev_1);
    EXPECT_EQ(dev_1->index, 0);
    EXPECT_EQ(dev_1->next, nullptr);
}

// ToDo: need to mock intr_run() in step4
// TEST(NetRunTest, RunDevice) {
//     struct net_device *dev_1;
//     struct net_device *dev_2;

//     net_device_register(dev_1);
//     net_device_register(dev_2);

//     net_run();

//     EXPECT_EQ(dev_1->flags & NET_DEVICE_FLAG_UP, NET_DEVICE_FLAG_UP);
//     EXPECT_EQ(dev_2->flags & NET_DEVICE_FLAG_UP, NET_DEVICE_FLAG_UP);
// }

TEST(NetProtocolRegister, RegisterProtocol) {
    uint16_t type = 0x1234;
    void (*handler)(const uint8_t*, size_t, struct net_device*) = nullptr;
    int result = net_protocol_register(type, handler);

    EXPECT_EQ(result, 0);
}

TEST(NetProtocolRegisterTest, ProtocolAlreadyRegistered) {
    uint16_t type = 0x2468;
    void (*handler)(const uint8_t*, size_t, struct net_device*) = nullptr;
    int result = net_protocol_register(type, handler);
    result = net_protocol_register(type, handler);

    EXPECT_EQ(result, -1);
}

TEST(NetInputHandlerTest, ProtocolAlreadyRegistered) {
    uint16_t type = 0x2468;
    void (*handler)(const uint8_t*, size_t, struct net_device*) = nullptr;
    int result = net_protocol_register(type, handler);
    result = net_protocol_register(type, handler);

    EXPECT_EQ(result, -1);
}
