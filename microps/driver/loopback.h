#ifndef LOOPBACK_H
#define LOOPBACK_H

#include "net.h"
#include "util.h"
#include "intr.h"
#include "platform.h"

struct net_device *loopback_init(void);

#endif