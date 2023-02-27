#ifndef ICMP_H
#define ICMP_H

#include "ip.h"
#include "util.h"

#define IP_PROTOCOL_ICMP 0x01

void icmp_input(const uint8_t *data, size_t len, ip_addr_t src, ip_addr_t dst, struct ip_iface *iface);
int icmp_init(void);

#endif