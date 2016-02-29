/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 16:32:47 by erobert           #+#    #+#             */
/*   Updated: 2014/06/27 10:37:43 by jchichep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include <unistd.h>

typedef struct	s_env
{
	char		*team_name;
	char		*port;
	char		*hostname;
}				t_env;

int				get_next_line(int fd, char **line);
size_t			ft_strlen(const char *s);
char			*ft_strdup(char *str);
char			*ft_strcpy(char *s1, const char *s2);
char			*ft_strncpy(char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
char			*ft_strnew(size_t size);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
int				ft_getline(int const fd, char **line);
int				ft_print_result(char *s1, char *s2, int res);
int				ft_lexer(int ac, char **av, t_env *e);
void			ft_send(char *str, int sock);
char			*ft_recv(int sock);
int				ft_client_create(char *addr, int port);
void			new_client(int ac, char **av, int lvl);
void			pondeur_init(int ac, char **av, int new);
void			pondeur(int sock, int max, int ac, char **av);
void			lvl_1_init(int ac, char **av);
void			lvl_1(int ac, char **av, int new);

#endif
