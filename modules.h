#pragma once

int is_ip_tcp(unsigned char *packet, int *ip_hl);
int is_tls(unsigned char *packet);
int parse_host(unsigned char *packet, char *domain);
int func(unsigned char *packet, char *domain);