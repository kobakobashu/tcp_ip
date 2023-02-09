#include <gtest/gtest.h>

extern "C" 
{
    #include "../util.h"
}

TEST(QueueInitTest, CorrectInit){
    struct queue_head queue;
    queue_init(&queue);

    EXPECT_EQ(NULL, queue.head);
    EXPECT_EQ(NULL, queue.tail);
    EXPECT_EQ(0, queue.num);
}

TEST(QueuePushTest, NullQueue) {
    struct queue_head *queue = NULL;
    int data = 10;
    void *result = queue_push(queue, &data);
    EXPECT_EQ(NULL, result);
}

TEST(QueuePush, NormalPush) {
    struct queue_head queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.num = 0;
    int data = 10;
    void *result = queue_push(&queue, &data);
    EXPECT_EQ(data, *(int*)result);
    EXPECT_EQ(1, queue.num);
    EXPECT_EQ(&data, queue.head->data);
    EXPECT_EQ(NULL, queue.head->next);
    EXPECT_EQ(queue.head, queue.tail);
}

TEST(QueuePop, NullQueue) {
    struct queue_head queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.num = 0;
    void *result = queue_pop(&queue);
    EXPECT_EQ(NULL, result);
    EXPECT_EQ(0, queue.num);
    EXPECT_EQ(NULL, queue.head);
    EXPECT_EQ(NULL, queue.tail);
}

TEST(QueuePop, NormalPop) {
    struct queue_head queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.num = 0;
    int data1 = 10;
    int data2 = 20;
    queue_push(&queue, &data1);
    queue_push(&queue, &data2);
    void *result = queue_pop(&queue);
    EXPECT_EQ(data1, *(int*)result);
    EXPECT_EQ(1, queue.num);
    EXPECT_EQ(queue.head, queue.tail);
    EXPECT_EQ(&data2, queue.head->data);
    result = queue_pop(&queue);
    EXPECT_EQ(data2, *(int*)result);
    EXPECT_EQ(0, queue.num);
    EXPECT_EQ(NULL, queue.head);
    EXPECT_EQ(NULL, queue.tail);
}

TEST(QueuePeek, NullQueue) {
    struct queue_head *queue = NULL;
    void *result = queue_peek(queue);
    EXPECT_EQ(NULL, result);
}

TEST(QueuePop, NormalPeek) {
    struct queue_head queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.num = 0;
    int data = 10;
    queue_push(&queue, &data);
    void *result = queue_peek(&queue);
    EXPECT_EQ(data, *(int*)result);
}

TEST(QueueForeachTest, NormalForeach) {
    struct queue_head queue;
    queue.head = NULL;
    queue.tail = NULL;
    queue.num = 0;
    int data1 = 1;
    int data2 = 2;
    int data3 = 3;
    int count = 0;

    queue_push(&queue, &data1);
    queue_push(&queue, &data2);
    queue_push(&queue, &data3);

    queue_foreach(&queue, [](void *arg, void *data) {
        ++(*static_cast<int*>(arg));
        EXPECT_EQ(*static_cast<int*>(data), *static_cast<int*>(arg));
    }, &count);

    EXPECT_EQ(count, 3);
}

TEST(Cksum16Test, Test1) {
    uint16_t addr[] = {0x0100, 0x0304, 0x0506, 0x0708};
    uint16_t count = sizeof(addr)/sizeof(uint16_t);
    uint32_t init = 0x00000000;
    uint16_t result = 0xfbfb;

    EXPECT_EQ(cksum16(addr, count, init), result);
}

TEST(Cksum16Test, Test2) {
    uint16_t addr[] = {0x0000, 0x0000, 0x0000, 0x0000};
    uint16_t count = sizeof(addr)/sizeof(uint16_t);
    uint32_t init = 0x00000000;
    uint16_t result = 0xffff;

    EXPECT_EQ(cksum16(addr, count, init), result);
}