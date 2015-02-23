/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell1.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/23 12:58:27 by erobert           #+#    #+#             */
/*   Updated: 2015/02/23 13:19:06 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MINISHELL1_H
# define FT_MINISHELL1_H

# include <unistd.h>

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define END "\033[0m"

typedef struct	s_cmd
{
	char		**av;
	char		*path;
	char		*file;
	int			fd[2];
	int			two[2];
}				t_cmd;

typedef struct termios	t_termios;

void			*ft_memmove(void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strjoin(char const *s1, char const *s2);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
int				ft_getline(int const fd, char **str);
char			**ft_strsplit(char const *s, char c);
int				ft_tty(void);
int				ft_outchar(int c);
void			ft_mode(int mode);
char			**ft_cpyenv(void);
int				ft_env(char **tab, char ***env);
void			ft_print_env(char **env);
void			ft_putprompt(char **env);
void			ft_cd(char **tab, char **env);
int				ft_gotpipe(char *str);
void			ft_pipe(char *str, char ***env);
int				ft_gotredirection(t_cmd *cmd, char *str);
void			ft_redirection(t_cmd *cmd, char *line, char ***env);
int				ft_getcmd(t_cmd *cmd, char *str, char **env);
void			ft_exec(int f, t_cmd *cmd, char *str, char ***env);

#endif
