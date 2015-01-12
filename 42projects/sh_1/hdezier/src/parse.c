#include "ft_minishell.h"
#include <fcntl.h>
#include <unistd.h>

#include <sys/types.h>
#include <dirent.h>

char		*read_user(void)
{
	char	*buf;
	int		r;

	buf = (char *)malloc((BUFF_SIZE + 1) * sizeof(char));
	r = read(0, buf, BUFF_SIZE);
	buf[r] = '\0';
	return (buf);
}

static char	*get_valid_path(char **paths, char *exe)
{
	int				i;
	DIR				*d;
	struct dirent	*dir;

	i = -1;
	while (paths[++i] != NULL)
	{
		if ((d = opendir(paths[i])))
		{
			while ((dir = readdir(d)))
			{
				if ((ft_strcmp(exe, dir->d_name)) == 0)
					return (paths[i]);
			}
			closedir(d);
		}
	}
	return (NULL);
}

static void	get_env(t_cmd *cmd)
{
	extern char		**environ;
	int				i;

	i = -1;
	cmd->env = environ;
	while (environ[++i])
	{
		if ((ft_strncmp(environ[i], "PATH", 4)) == 0)
		{
			cmd->path = get_valid_path(ft_strsplit(environ[i] + 5, ':'), cmd->exe);
			cmd->path = ft_strjoin(cmd->path, "/");
			break ;
		}
	}
}

void		parse(t_cmd *cmd, char *s)
{
	char		**split_cmd;
	int			i;

	i = -1;
	split_cmd = ft_strsplit(s, ' ');
	while (split_cmd[++i])
		split_cmd[i] = ft_strtrim(split_cmd[i]);
	cmd->exe = split_cmd[0];
	if (split_cmd)
		cmd->args = split_cmd;
	else
		cmd->args = NULL;
	cmd->path = NULL;
	get_env(cmd);
}
