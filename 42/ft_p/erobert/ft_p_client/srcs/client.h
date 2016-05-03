/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:32:47 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 15:33:49 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define END "\033[0m"

# define GET 1
# define PUT 2
# define PWD 3
# define CD 4
# define LS 5
# define QUIT 6

typedef struct	s_request
{
	int			cmd;
	char		av[1024];
}				t_request;

char			*ft_strcpy(char *s1, const char *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
int				ft_getline(int const fd, char **line);
int				ft_print_result(char *s1, char *s2, int res);
int				ft_getfile(int sock, char *file);
int				ft_putfile(int sock, char *file);
int				ft_pwd(int sock);
int				ft_cd(int sock, char *av);
int				ft_ls(int sock);
void			ft_client_loop(int sock, char **av);

#endif
