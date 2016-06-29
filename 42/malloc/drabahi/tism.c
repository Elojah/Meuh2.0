#include "malloc.h"

static int		page_size(int type)
{
	int	a;
	int	ps;

	a = 128 * type;
	ps = getpagesize();
	if (type % ps)
		return ((a / ps + 1) * ps) 
	else
		return (a)
}

t_header	*shift_header(t_header *cast)
{
	char	*temp;

	temp = (char *)cast;
	temp = temp + cast->size + sizeof(t_header);
	return ((t_header *)temp)
}

void	alloc_tism(size_t n, t_header **stock, size_t type)
{
	size_t		length;
	t_header	*tmp;

	tmp = *stock;
	if (!tmp)
	{
		length = page_size(type);
		tmp = mmap(0, length, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANON, -1, 0);
		*stock = tmp;
		tmp->size = (length - (sizeof(t_header) * 2));
		tmp->state = 0;
		tmp = shift_header(tmp);
		tmp->size = 0;
		tmp->state = 2;
		tmp = *stock;
	}
	while (tmp->state)
	{
		if (tmp->state == 2)
		{}
// Le cas ou il faut realouer une plage complete !!!! 
// et ou la premiere est plein il faut passer a l'autre
		tmp = shift_header(tmp);
	}
}


