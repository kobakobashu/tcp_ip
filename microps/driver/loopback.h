#ifndef LOOPBACK_H
#define LOOPBACK_H

#include "net.h"
#include "util.h"
#include "intr.h"
#include "platform.h"

#define LOOPBACK_MTU UINT16_MAX /* maximum size of IP datagram */
#define LOOPBACK_QUEUE_LIMIT 16
#define LOOPBACK_IRQ (INTR_IRQ_BASE+1)

struct net_device *loopback_init(void);

#endif