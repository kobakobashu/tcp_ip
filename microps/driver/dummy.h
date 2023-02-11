#ifndef DUMMY_H
#define DUMMY_H

#define DUMMY_MTU UINT16_MAX

extern struct net_device_ops dummy_ops;
struct net_device *dummy_init(void);

#endif