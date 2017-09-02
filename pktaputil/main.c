//
//  main.c
//  pktaputil
//
//  Created by Tomoyuki Sahara on 2017/09/02.
//  Copyright © 2017 Tomoyuki Sahara. All rights reserved.
//

// #include <net/pktap.h>

#include <pcap/pcap.h>
#include <err.h>
#include <stdio.h>


char errbuf[PCAP_ERRBUF_SIZE];

extern int pcap_set_want_pktap(pcap_t *, int);


int main(int argc, const char * argv[]) {
    pcap_t *pcap;

    pcap = pcap_create("pktap0", errbuf);
    if (pcap == NULL)
        err(1, "pcap_create");

    pcap_set_want_pktap(pcap, 1);

    printf("Hello, World!\n");
    return 0;
}
