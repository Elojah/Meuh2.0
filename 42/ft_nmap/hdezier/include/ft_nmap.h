/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:37:46 by leeios            #+#    #+#             */
/*   Updated: 2017/01/02 13:17:06 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_H
# define FT_NMAP_H

# ifndef NULL
#  define NULL 0x0
# endif

# include "list.h"

# include <netinet/tcp.h>
# include <netinet/ip.h>

// TCP/IP packet struct
typedef enum			e_bits
{
	B_1 =		0b00000001,
	B_2 =		0b00000010,
	B_3 =		0b00000100,
	B_4 =		0b00001000,
	B_5 =		0b00010000,
	B_6 =		0b00100000,
	B_7 =		0b01000000,
	B_8 =		0b10000000
}						t_bits;
typedef struct			s_datagram
{
	struct iphdr		iph;
	struct tcphdr		tcph;
}						t_datagram;

// Error handling
typedef enum			e_err
{
						NONE = -1,
						WIP = 0,
						HELP,
						DEVICE_OPEN,
						UNKNOWN_HOSTNAME,
						LOCAL_CONNECT,
						SOCKET_OPTIONS,
}						t_err;

// Ports definnition
typedef struct			s_ports
{
	char				n[1024];
	unsigned int		size;
}						t_ports;

// Arguments specification definition
typedef unsigned short	t_threads_n;
typedef unsigned char	t_scan_mask;
typedef enum			e_scan_types
{
	SYN =		B_1,
	NULL_SCAN =	B_2,
	ACK =		B_3,
	FIN =		B_4,
	XMAS =		B_5,
	UDP =		B_6
}						t_scan_types;

typedef struct			s_spec
{
	t_ports				ports;
	t_list				ip_adresses;
	t_threads_n			n_threads;
	t_scan_mask			scan;
}						t_spec;

// Args map
typedef struct			s_args_map
{
	char				*ports;
	char				*ip;
	char				*file;
	char				*speedup;
	char				*scan;
}						t_args_map;

// scan_args.c
t_err		scan_args(int ac,char **av, t_spec *specs);
// set_args.c
t_err		set_args(t_args_map *args_map, t_spec *specs);
// set_ports.c
t_err		set_ports(char *arg, t_ports *ports);
// set_ip.c
t_err		set_ip(char *arg, t_list *adresses);
t_err		set_ip_from_file(char *filename, t_list *adresses);
// set_scan_mask.c
t_err		set_scan_mask(char *arg, t_scan_mask *mask);
void		print_scan_mask(t_scan_mask *mask);

// launch_scan.c
t_err		launch_scan(t_spec *specs);

#endif

