#ifndef IP_H
#define IP_H

#include "net.h"

#define IP_VERSION_IPV4 4

#define IP_HDR_SIZE_MIN 20
#define IP_HDR_SIZE_MAX 60

#define IP_ADDR_LEN 4
#define IP_ADDR_STR_LEN 16

typedef uint32_t ip_addr_t;

int ip_init(void);
int ip_addr_pton(const char *p, ip_addr_t *n);
char *ip_addr_ntop(ip_addr_t n, char *p, size_t size);
void ip_dump(const uint8_t *data, size_t len);

#endif