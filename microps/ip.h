#ifndef IP_H
#define IP_H

#include <sys/types.h>
#include "net.h"

#define IP_VERSION_IPV4 4

#define IP_HDR_SIZE_MIN 20
#define IP_HDR_SIZE_MAX 60

#define IP_TOTAL_SIZE_MAX UINT16_MAX /* maximum value of uint16 */
#define IP_PAYLOAD_SIZE_MAX (IP_TOTAL_SIZE_MAX - IP_HDR_SIZE_MIN)

#define IP_ADDR_LEN 4
#define IP_ADDR_STR_LEN 16

#define IP_ENDPOINT_STR_LEN (IP_ADDR_STR_LEN + 6) /* xxx.xxx.xxx.xxx:yyyyy\n */

#define IP_PROTOCOL_TCP  0x06
#define IP_PROTOCOL_UDP  0x11

typedef uint32_t ip_addr_t;

struct ip_endpoint {
    ip_addr_t addr;
    uint16_t port;
};

struct ip_iface {
    struct net_iface iface;
    struct ip_iface *next;
    ip_addr_t unicast;
    ip_addr_t netmask;
    ip_addr_t broadcast;
};

extern const ip_addr_t IP_ADDR_ANY;
extern const ip_addr_t IP_ADDR_BROADCAST;

int ip_init(void);
int ip_addr_pton(const char *p, ip_addr_t *n);
char *ip_addr_ntop(ip_addr_t n, char *p, size_t size);
void ip_dump(const uint8_t *data, size_t len);
struct ip_iface *ip_iface_alloc(const char *unicast, const char *netmask);
int ip_iface_register(struct net_device *dev, struct ip_iface *iface);
struct ip_iface *ip_iface_select(ip_addr_t addr);
ssize_t ip_output(uint8_t protocol, const uint8_t *data, size_t len, ip_addr_t src, ip_addr_t dst);
int ip_protocol_register(uint8_t type, void (*handler)(const uint8_t *data, size_t len, ip_addr_t src, ip_addr_t dst, struct ip_iface *iface));
int ip_route_set_default_gateway(struct ip_iface *iface, const char *gateway);
struct ip_iface *ip_route_get_iface(ip_addr_t dst);
int ip_endpoint_pton(const char *p, struct ip_endpoint *n);
char *ip_endpoint_ntop(const struct ip_endpoint *n, char *p, size_t size);

#endif