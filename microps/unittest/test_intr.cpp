#include <gtest/gtest.h>

extern "C"
{
    #include "../platform/linux/intr.h"
}

#define INTR_IRQ_EDGE 0x0000

TEST(IntrRequestIrqTest, RegisterIrq) {
    unsigned int irq = 1;
    int flags = INTR_IRQ_SHARED;
    const char *name = "test_irq_1_valid";
    void *dev = nullptr;
    int result = intr_request_irq(irq, nullptr, flags, name, dev);
    ASSERT_EQ(result, 0);
}

TEST(IntrRequestIrqTest, InvalidFlags) {
    unsigned int irq_1 = 2;
    int flags_1 = INTR_IRQ_SHARED;
    const char *name_1 = "test_irq_2_valid";
    void *dev_1 = nullptr;
    int result_1 = intr_request_irq(irq_1, nullptr, flags_1, name_1, dev_1);
    ASSERT_EQ(result_1, 0);

    unsigned int irq_2 = 2;
    int flags_2 = INTR_IRQ_EDGE;
    const char *name_2 = "test_irq_2_invalid";
    void *dev_2 = nullptr;
    int result_2 = intr_request_irq(irq_2, nullptr, flags_2, name_2, dev_2);
    EXPECT_EQ(result_2, -1);
}

