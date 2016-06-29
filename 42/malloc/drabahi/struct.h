#include "malloc.h"

typedef struct	s_alloc
{
	t_header		*lst_tiny;
	t_header		*lst_small;
	t_large			*lst_large;
//	struct rlimit	limit;
}					t_alloc;

typedef struct	s_header
{
	size_t		size;
	char		state;
}				t_header;

/**
 * 	state 0 = libre, 1 = occuper, 2 = dernier
 **/

typedef struct	s_large
{
	t_large		*prev;
	t_large		*next;
	size_t		size;
}				t_large;