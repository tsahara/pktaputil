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

// hidden API of Apple version of libpcap
extern int pcap_set_want_pktap(pcap_t *, int);


int main(int argc, const char * argv[]) {
    pcap_t *pcap;
    int ret;

    pcap = pcap_create("pktap", errbuf);
    if (pcap == NULL)
        err(1, "pcap_create");

    if (pcap_set_snaplen(pcap, 128) != 0)
        errx(1, "pcap_set_snaplen");
    if (pcap_set_timeout(pcap, 1000) != 0)
        errx(1, "pcap_set_timeout");

    pcap_set_want_pktap(pcap, 1);
    ret = pcap_activate(pcap);
    warnx("acti => %d", ret);

    system("ifconfig pktap0");
    printf("Hello, World!\n");

    pcap_close(pcap);
    return 0;
}
