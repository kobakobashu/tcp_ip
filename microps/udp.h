#ifndef UDP_H
#define UDP_H

#include <stddef.h>
#include <stdint.h>

#include "ip.h"

ssize_t udp_output(struct ip_endpoint *src, struct ip_endpoint *dst, const uint8_t *buf, size_t len);
int udp_init(void);
int udp_open(void);
int udp_close(int id);
int udp_bind(int id, struct ip_endpoint *local);

#endif