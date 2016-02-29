/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   serveur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erobert <erobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/05/12 13:53:01 by erobert           #+#    #+#             */
/*   Updated: 2015/06/12 17:01:28 by erobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVEUR_H
# define SERVEUR_H

# include <unistd.h>
# include "libft.h"

# define SERVER 1
# define PLAYER 2
# define PLYEGG 3
# define GFXCLT 4

# define BUF_SIZE 1024
# define TEAM_MAX 42
# define UTOS 1000000

typedef enum		e_resource
{
	FOOD = 0,
	LINE,
	DERA,
	SIBU,
	MEND,
	PHIR,
	THYS,
	PLAY,
	E_RESOURCE
}					t_resource;

typedef enum		e_cmd
{
	ADVANCE,
	RIGHT,
	LEFT,
	SCAN,
	INVENTORY,
	TAKE,
	PUT,
	EXPEL,
	BROADCAST,
	INCANTATION,
	FORK,
	CONNECT,
	E_CMD
}					t_cmd;

typedef struct		s_cell
{
	int				resource[E_RESOURCE];
}					t_cell;

typedef struct		s_fd
{
	int				type;
	void			(*fct_read)();
	void			(*fct_write)();
	char			buf_read[BUF_SIZE];
	char			buf_write[BUF_SIZE];
	t_cmd			cmd; /*lst cmd */
	char			av[BUF_SIZE];
	struct timeval	time;
	int				team_number;
	char			level;
	struct timeval	hp;
	int				resource[7];
	int				pos[2];
	int				dir;
}					t_fd;

typedef struct		s_env
{
	char			*port;
	t_fd			*fds;
	int				mfds;
	int				nfds;
	int				rfds;
	int				gfx;
	fd_set			fd_read;
	fd_set			fd_write;
	int				client_nb[TEAM_MAX];
	char			team_name[TEAM_MAX][BUF_SIZE];
	int				time;
	int				width;
	int				height;
	t_cell			**trantor;
}					t_env;

size_t				ft_linelen(const char *s);
int					ft_linecmp(const char *s1, const char *s2);
int					ft_print_result(char *s1, char *s2, int res);
int					ft_lexer(int ac, char **av, t_env *e);
int					ft_trantor_init(t_env *e);
char				*ft_celltoa(int *resrc);
char				*ft_invtoa(int *resrc);
void				ft_putmsz_fd(t_env *e, int sock);
void				ft_putsgt_fd(t_env *e, int sock);
void				ft_putbct_fd(t_env *e, int x, int y, int sock);
void				ft_putpnw_fd(t_env *e, int psock, int gsock);
void				ft_putenw_fd(t_env *e, int psock, int gsock);
void				ft_putppo_fd(t_env *e, int psock, int gsock);
void				ft_putplv_fd(t_env *e, int psock, int gsock);
void				ft_putpin_fd(t_env *e, int psock, int gsock);
int					ft_check_cmd(t_env *e, int sock, char *str);
int					ft_check_resource(t_fd *fd, t_cell **trantor);
void				ft_trantor_scan(t_env *e, int sock);
int					ft_action_move(t_env *e, int sock, t_cmd cmd);
int					ft_action_object(t_env *e, int sock, t_cmd cmd, char *av);
int					ft_action_special(t_env *e, int sock, t_cmd cmd);
void				ft_sock_close(t_env *e, int sock);
void				ft_player_read(t_env *e, int sock);
void				ft_gfxclt_read(t_env *e, int sock);
void				ft_check_death(t_env *e);
void				ft_serveur_accept(t_env *e, int ssock);
void				ft_serveur_loop(t_env *e, int sock);

#endif
