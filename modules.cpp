#include "modules.h"
#include "headers.h"
#include "pch.h"

int is_ip_tcp(unsigned char *packet, u_int8_t *hl)
{
    ip_hdr *ip = (ip_hdr *)packet;
    if ((ip->ip_v == 4) && (ip->ip_protocol == 6))
    {
        *hl = ip->ip_hl;
        return 1;
    }
    else
    {
        return 0;
    }
}
int is_tls(unsigned char *packet, u_int8_t *hl)
{
    tcp_hdr *tcp = (tcp_hdr *)packet;
    if (*(uint8_t *)(packet + (tcp->tcp_offset * 4)) == 0x17)
    {
        printf("tls? : %d\n", *(uint8_t *)(packet + (tcp->tcp_offset * 4)));
        return 1;
    }
    else
    {
        *hl = *(uint8_t *)(packet + (tcp->tcp_offset * 4));
        printf("tls? : %d\n", *(uint8_t *)(packet + (tcp->tcp_offset * 4)));
        return 0;
    }
}
int parse_host(unsigned char *packet, unsigned char *domain)
{
    int i = 0;
    for (i; i < sizeof(packet); i++)
    {
        if (packet[i] != domain[i])
        {
            return 0;
        }
    }
    if (packet[i] !=) //////// host: 부터 시작
}

int func(unsigned char *packet, char *domain)
{
    u_int8_t ip_hl;
    u_int8_t tcp_hl;
    if (is_ip_tcp(packet, &ip_hl))
    {
        if (is_tls(packet + 4 * ip_hl, &tcp_hl))
        {
            return parse_host(packet + 4 * ip_ul + 4 * tcp_hl, domain);
        }
        return 0;
    }
    return 0;
}