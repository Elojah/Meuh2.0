/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:08:15 by leeios            #+#    #+#             */
/*   Updated: 2017/03/30 11:32:21 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "libstr.h"
#include "libmem.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/socket.h>

#include <pcap.h>

static void	print_config(t_spec *specs)
{
	printf("Scan configurations\n");
	printf("Target Ip-Address :");
	print_list(&specs->ip_adresses);
	printf("\nNo of Ports to scan : %u\n", specs->ports.size);
	printf("Scans to be perform :");
	print_scan_mask(&specs->scan);
	printf("\nNo of threads : %u\n", specs->n_threads);
}

/*
Checksums - IP and TCP
*/
unsigned short	csum(unsigned short *ptr,int nbytes)
{
	long			sum;
	unsigned short	oddbyte;
	short			answer;

	sum=0;
	while (nbytes > 1)
	{
		sum += *ptr++;
		nbytes -= 2;
	}
	if (nbytes == 1)
	{
		oddbyte = 0;
		*((u_char*)&oddbyte) = *(u_char*)ptr;
		sum += oddbyte;
	}
	sum = (sum>>16)+(sum & 0xffff);
	sum = sum + (sum>>16);
	answer = (short)~sum;
	return(answer);
}

/*
	Get ip from domain name
 */
t_err		set_hostname(char *hostname, in_addr_t *dest)
{
	struct hostent	*he;
	struct in_addr	**addr_list;
	int				addr;

	if (hostname == NULL)
		return (UNKNOWN_HOSTNAME);
	addr = inet_addr(hostname);
	if (addr != -1)
	{
		*dest = addr;
		return (NONE);
	}
	he = gethostbyname(hostname);
	if (he == NULL)
		return (UNKNOWN_HOSTNAME);
	addr_list = (struct in_addr **)he->h_addr_list;
	if (addr_list[0] == NULL)
		return (UNKNOWN_HOSTNAME);
	*dest = inet_addr(inet_ntoa(*addr_list[0]));
	printf("Resolved hostname %s\n", hostname);
	return (NONE);
}

/*
 Get source IP of system , like 192.168.0.6 or 192.168.1.2
 */
t_err	set_local_ip(char *buffer)
{
	static const char	*k_google_dns_ip = "8.8.8.8";
	struct sockaddr_in	serv;
	struct sockaddr_in	name;
	socklen_t			namelen;
	int					sock;

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	ft_memset(&serv, 0, sizeof(serv));
	serv.sin_family = AF_INET;
	serv.sin_addr.s_addr = inet_addr(k_google_dns_ip);
	serv.sin_port = htons(53);
	if (connect(sock , (const struct sockaddr*)&serv, sizeof(serv)) != 0)
		return (LOCAL_CONNECT);
	namelen = sizeof(name);
	if (getsockname(sock, (struct sockaddr*)&name, &namelen) != 0)
		return (LOCAL_CONNECT);
	inet_ntop(AF_INET, &name.sin_addr, buffer, 100);
	close(sock);
	return (NONE);
}



void process_packet(unsigned char* buffer, int size)
{
	(void)size;
    //Get the IP Header part of this packet
    struct iphdr *iph = (struct iphdr*)buffer;
    struct sockaddr_in source,dest;
    unsigned short iphdrlen;

    if(iph->protocol == 6)
    {
        struct iphdr *iph = (struct iphdr *)buffer;
        iphdrlen = iph->ihl*4;

        struct tcphdr *tcph=(struct tcphdr*)(buffer + iphdrlen);

        ft_memset(&source, 0, sizeof(source));
        source.sin_addr.s_addr = iph->saddr;

        ft_memset(&dest, 0, sizeof(dest));
        dest.sin_addr.s_addr = iph->daddr;

        if(tcph->syn == 1 && tcph->ack == 1)// && source.sin_addr.s_addr == dest_ip.s_addr )
        {
            printf("Port %d open \n" , ntohs(tcph->source));
            fflush(stdout);
        }
    }
}

int start_sniffer()
{
    int sock_raw;

    unsigned int saddr_size;
    int data_size;
    struct sockaddr saddr;

    unsigned char *buffer = (unsigned char *)malloc(65536); //Its Big!

    printf("Sniffer initialising...\n");
    fflush(stdout);

    //Create a raw socket that shall sniff
    sock_raw = socket(AF_INET , SOCK_RAW , IPPROTO_TCP);

    if(sock_raw < 0)
    {
        printf("Socket Error\n");
        fflush(stdout);
        return 1;
    }

    saddr_size = sizeof(saddr);

    while(1)
    {
    	printf("Waiting for \n");
        //Receive a packet
        data_size = recvfrom(sock_raw , buffer , 65536 , 0 , &saddr , &saddr_size);

        if(data_size <0 )
        {
            printf("Recvfrom error , failed to get packets\n");
            fflush(stdout);
            return 1;
        }

        //Now process the packet
        process_packet(buffer , data_size);
    }

    close(sock_raw);
    printf("Sniffer finished.");
    fflush(stdout);
    return 0;
}
/*
    Method to sniff incoming packets and look for Ack replies
*/
void	*receive_ack( void *ptr )
{
	(void)ptr;
    //Start the sniffer thing
    start_sniffer();
    return (NULL);
}

t_err		launch_scan(t_spec *specs)
{
	print_config(specs);
	printf("Scanning...\n");

	// char	*dev,	errbuf[PCAP_ERRBUF_SIZE];
	// dev = pcap_lookupdev(errbuf);
	// printf("Device: %s\n", dev);

	// pcap_t *handle;

	// struct bpf_program filter;              /* The compiled filter expression */
	// char filter_app[] = "port 23";          /* The filter expression */
	// bpf_u_int32 mask;                       /* The netmask of our sniffing device */
	// bpf_u_int32 net;                          /* The IP of our sniffing device */
	// pcap_lookupnet(dev, &net, &mask, errbuf);
	// handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
	// if (handle == NULL) {
	// 	fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
	// 	return (DEVICE_OPEN);
	// }
	// pcap_compile(handle, &filter, filter_app, 0, net);
	// pcap_setfilter(handle, &filter);

	if (specs->ip_adresses.head == NULL)
		return (UNKNOWN_HOSTNAME);

	t_datagram		t;
	t_err			error;
	char			source_ip[20];
	struct in_addr	dest_ip;
	error = set_local_ip(source_ip);
	if (error != NONE)
		return (error);
	error = set_hostname((char *)specs->ip_adresses.head->data, &dest_ip.s_addr);
	if (error != NONE)
		return (error);

	t.iph.version = htons(4);
	t.iph.tos = 0; // Type of service, may set precedence, flash, etc. here
	t.iph.tot_len = sizeof(t_datagram);
	t.iph.id = htons(42); // id, generate randomly ?
	t.iph.frag_off = 0; // First fragment has offset 0
	t.iph.ttl = htons(255); // 0 for localhost to 255 for unrestricted
	t.iph.protocol = IPPROTO_TCP;
	// Set adresses from/to
	t.iph.saddr = inet_addr(source_ip);
	t.iph.daddr = dest_ip.s_addr;
	t.iph.ihl = htons(5); // Header length
	t.iph.check = csum ((unsigned short *)&t, t.iph.tot_len >> 1);

	//TCP Header
	int source_port = 4242;
	t.tcph.source = htons(source_port);
	t.tcph.dest = htons(80);
	t.tcph.seq = 0;
	t.tcph.ack_seq = 0;
	t.tcph.doff = sizeof(struct tcphdr) / 4; //Size of tcp header


	t.tcph.syn=1;
	t.tcph.ack=0;
	t.tcph.fin=0;

	t.tcph.rst=0;
	t.tcph.psh=0;
	t.tcph.urg=0;

	t.tcph.window = htons(14600); // maximum allowed window size
	t.tcph.check = 0; //if you set a checksum to zero, your kernel's IP stack should fill in the correct checksum during transmission
	t.tcph.urg_ptr = 0;

	printf("TCP options OK\n");

	int			one = 1;
	const int	*val = &one;


	int s = socket(AF_INET, SOCK_RAW , IPPROTO_TCP);
	//IP_HDRINCL to tell the kernel that headers are included in the packet
	if (setsockopt(s, IPPROTO_IP, IP_HDRINCL, val, sizeof (one)) < 0)
		return (SOCKET_OPTIONS);

	printf("Socket options OK\n");

	char	*message1 = (char *)"Thread 1";
	// int  iret1;
	pthread_t sniffer_thread;

	if( pthread_create( &sniffer_thread , NULL ,  receive_ack , (void*) message1) < 0)
	{
		printf ("Could not create sniffer thread. Error number :  . Error message : \n" );
		exit(0);
	}

	printf("Starting to send syn packets\n");

	int port;
	struct sockaddr_in  dest;
	dest.sin_family = AF_INET;
	dest.sin_addr.s_addr = dest_ip.s_addr;
	for (port = 1 ; port < 1024 ; port++)
	{
		if (specs->ports.n[port] == 0)
			continue ;
		t.tcph.dest = htons ( port );
		t.tcph.check = 0; // if you set a checksum to zero, your kernel's IP stack should fill in the correct checksum during transmission

		// psh.source_address = inet_addr( source_ip );
		// psh.dest_address = dest.sin_addr.s_addr;
		// psh.placeholder = 0;
		// psh.protocol = IPPROTO_TCP;
		// psh.tcp_length = htons( sizeof(struct tcphdr) );

		// memcpy(&psh.tcp , t.tcph. sizeof (struct tcphdr));

		// t.tcph.check = csum( (unsigned short*) &psh , sizeof (struct pseudo_header));

		//Send the packet
		if ( sendto (s, &t , sizeof(struct iphdr) + sizeof(struct tcphdr) , 0 , (struct sockaddr *) &dest, sizeof (dest)) < 0)
		{
			printf ("Error sending syn packet. Error number : . Error message : \n");
			exit(0);
		}
	}

	pthread_join( sniffer_thread , NULL);
	// printf("%d" , iret1);


	return (WIP);
}
