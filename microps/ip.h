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

#endif