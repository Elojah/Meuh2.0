/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:37:46 by leeios            #+#    #+#             */
/*   Updated: 2016/12/29 21:27:38 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_H
# define FT_NMAP_H

// Error handling
typedef enum			e_err
{
						NONE = 0,
						WIP,
						HELP,
						ARGS_WRONG_FORMAT
}						t_err;

// Ports definnition
typedef struct			s_ports
{
	char				n[1024];
}						t_ports;

// Arguments specification definition
typedef unsigned short	t_threads_n;
typedef unsigned char	t_scan_mask;
typedef enum			e_scan_types
{
	SYN =		0x01,
	NULL_SCAN =	0x02,
	ACK =		0x04,
	FIN =		0x08,
	XMAS =		0x10,
	UDP =		0x20
}						t_scan_types;

typedef struct			s_spec
{
	t_ports				ports;
	char				**ip_adresses;
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
t_err		set_args(const t_args_map *args_map, t_spec *specs);
// set_ports.c
t_err		set_ports(char *arg, t_ports *ports);

#endif

