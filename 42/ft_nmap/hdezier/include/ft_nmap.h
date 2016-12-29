/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nmap.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/29 11:37:46 by leeios            #+#    #+#             */
/*   Updated: 2016/12/29 14:01:01 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_NMAP_H
# define FT_NMAP_H

// Error handling
typedef enum			e_err
{
						NONE = 0,
						HELP,
						ARGS_WRONG_FORMAT
}						t_err;

// Ports definnition
typedef unsigned short	t_port_n;
typedef struct			s_range
{
	t_port_n			start;
	t_port_n			end;
}						t_range;

typedef struct			s_ports
{
	t_range				*ranges;
	t_port_n			*n;
}						t_ports;

// Arguments specification definition
typedef unsigned short	t_threads_n;
typedef unsigned int	t_scan_mask;
typedef enum			e_scan_types
{
	SYN =		0x00000001,
	NULL_SCAN =	0x00000010,
	ACK =		0x00000100,
	FIN =		0x00001000,
	XMAS =		0x00010000,
	UDP =		0x00100000
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

// Scan_args
t_err		scan_args(int ac,char **av, t_spec *specs);

#endif
