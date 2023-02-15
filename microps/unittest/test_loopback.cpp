#include <gtest/gtest.h>

extern "C"
{
    #include "../driver/loopback.h"
}

TEST(LoopbackInitTest, CorrectInit){
    struct net_device *dev;
    dev = loopback_init();
    EXPECT_TRUE(dev != NULL);
    EXPECT_EQ(NET_DEVICE_TYPE_LOOPBACK, dev->type);
    EXPECT_EQ(LOOPBACK_MTU, dev->mtu);
    EXPECT_EQ(0, dev->hlen);
    EXPECT_EQ(0, dev->alen);
    EXPECT_EQ(NET_DEVICE_FLAG_LOOPBACK, dev->flags);
}