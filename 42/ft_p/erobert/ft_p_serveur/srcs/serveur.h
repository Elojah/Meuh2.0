/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:53:01 by erobert           #+#    #+#             */
/*   Updated: 2014/05/14 18:03:46 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <unistd.h>

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

size_t			ft_strlen(const char *s);
char			*ft_strcpy(char *s1, const char *s2);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
int				ft_getfile(int sock, char *file);
int				ft_putfile(int sock, char *file);
int				ft_pwd(int sock, char *pwd);
int				ft_cd(int sock, char **pwd, char *path, int r);
int				ft_ls(int sock);
void			ft_serveur_loop(int sock);

#endif
