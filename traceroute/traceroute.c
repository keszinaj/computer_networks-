#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include "send.h"
#include "receive.h"
int traceroute(char *ip)
{
    int sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
    printf("traceroute");
	if (sockfd < 0) {
		fprintf(stderr, "socket error: %s\n", strerror(errno)); 
		return EXIT_FAILURE;
	}
    int t;
    for(t =1; t < 10; t++)
    {
    if(!sendppp(sockfd, ip, t))
    {
        receive(sockfd);
    }
    }
    return 0;
}