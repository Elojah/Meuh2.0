#include <stdlib.h>
#include "libft.h"

void	ft_exit(int test, char *err_msg)
{
	if (!test)
		return ;
	else
	{
		ft_putendl_fd(err_msg, 2);
		exit(1);
	}
}
