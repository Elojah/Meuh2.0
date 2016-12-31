/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_scan.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/30 17:08:15 by leeios            #+#    #+#             */
/*   Updated: 2016/12/31 14:53:35 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_nmap.h"
#include "libstr.h"
#include "libmem.h"

#include <stdio.h>
#include <unistd.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <pcap.h>

static void	print_config(t_spec *specs)
{
	printf("Scan configurations\n");
	printf("Target Ip-Address :\n");
	print_list(&specs->ip_adresses);
	printf("No of Ports to scan : %u\n", specs->ports.size);
	printf("Scans to be perform :");
	print_scan_mask(&specs->scan);
	printf("\n");
	printf("No of threads : %u\n", specs->n_threads);
}

// static int		create_client(char *addr, int port)
// {
// 	int					sock;
// 	struct protoent		*proto;
// 	struct sockaddr_in	sin;
// 	static const char	localhost[] = "127.0.0.1";

// 	proto = getprotobyname("tcp");
// 	if (proto == 0)
// 		return (-1);
// 	if (ft_strcmp(addr, "localhost") == 0)
// 		addr = (char *)localhost;
// 	sock = socket(PF_INET, SOCK_STREAM, proto->p_proto);
// 	sin.sin_family = AF_INET;
// 	sin.sin_port = htons(port);
// 	sin.sin_addr.s_addr = inet_addr(addr);
// 	if (connect(sock, (const struct sockaddr *)&sin, sizeof(sin)) == -1)
// 		sock = -1;
// 	return (sock);
// }

/*
	Get ip from domain name
 */
t_err		set_hostname(char *hostname, in_addr_t *dest)
{
	struct hostent	*he;
	struct in_addr	**addr_list;
	int				addr;

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
	return (UNKNOWN_HOSTNAME);
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

	sock = socket( AF_INET, SOCK_DGRAM, 0);
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

t_err		launch_scan(t_spec *specs)
{
	print_config(specs);
	printf("Scanning...\n");

	char	*dev,	errbuf[PCAP_ERRBUF_SIZE];
	dev = pcap_lookupdev(errbuf);
	printf("Device: %s\n", dev);

	pcap_t *handle;

	struct bpf_program filter;              /* The compiled filter expression */
	char filter_app[] = "port 23";          /* The filter expression */
	bpf_u_int32 mask;                       /* The netmask of our sniffing device */
	bpf_u_int32 net;                          /* The IP of our sniffing device */
	pcap_lookupnet(dev, &net, &mask, errbuf);
	handle = pcap_open_live(dev, BUFSIZ, 1, 1000, errbuf);
	if (handle == NULL) {
		fprintf(stderr, "Couldn't open device %s: %s\n", dev, errbuf);
		return (DEVICE_OPEN);
	}
	pcap_compile(handle, &filter, filter_app, 0, net);
	pcap_setfilter(handle, &filter);

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
	// Header length, set at the end
	t.iph.ihl = htons(5);

	return (WIP);
}
