#ifndef FT_MINISHELL_H
#define FT_MINISHELL_H

# define IS_DIGIT(n) ((n) >= '0' && (n) <= '9')
# define BUFF_SIZE 1024

# include <stdlib.h>

typedef struct	s_cmd
{
	char		*exe;
	char		**args;
	char		**env;
}				t_cmd;

/*
**PARSE
*/
char		*read_user(void);
t_cmd		*parse(char *s);

/*
**CALCULUS
*/
void		exec_cmd(t_cmd *cmd);

/*
**LIBFT
*/
void		ft_exit(int test, char *s);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strjoin(char *s, char *t);
int			ft_uatoi(char **nbr);

#endif
