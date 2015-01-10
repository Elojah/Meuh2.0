#include "ft_minishell.h"
#include <fcntl.h>
#include <unistd.h>

char		*read_user(void)
{
	char	*buf;
	int		r;

	buf = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
	r = read(0, buf, BUFF_SIZE);
	buf[r] = '\0';
	return (buf);
}

t_cmd		*parse(char *s)
{
	t_cmd		*cmd;

	cmd = (t_cmd *)malloc(sizeof(t_cmd));

	cmd->args = (char **)malloc(2 * sizeof(char *));
	cmd->env = NULL;

	/*some stuff to do*/
	cmd->exe = ft_strjoin("/bin/", s);
	cmd->args[0] = ft_strjoin(cmd->exe, "");
	cmd->args[1] = NULL;

	return (cmd);
}
