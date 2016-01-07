/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_to_pieces.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leeios <leeios@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 18:49:43 by leeios            #+#    #+#             */
/*   Updated: 2015/12/27 18:01:22 by leeios           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "tetris.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

static int	consecutive_bloc(t_piece *piece, int i, int j, long *check_mask)
{
	if (i < 0 || i >= SIZE_PIECE
		|| j < 0 || j >= SIZE_PIECE
		|| (((*check_mask >> (i * SIZE_PIECE + j)) & 1) != 0)
		|| piece->data[i][j] != BLOC)
		return (0);
	*check_mask |= (1 << (i * SIZE_PIECE + j));
	return(1
		+ consecutive_bloc(piece, i + 1, j, check_mask)
		+ consecutive_bloc(piece, i, j + 1, check_mask)
		+ consecutive_bloc(piece, i - 1, j, check_mask)
		+ consecutive_bloc(piece, i, j - 1, check_mask)
		);
}

static t_error	is_valid_piece_four_consecutive(t_piece *piece)
{
	int		i;
	int		j;
	long	check_mask;

	i = -1;
	while (++i < SIZE_PIECE)
	{
		j = -1;
		while (++j < SIZE_PIECE)
		{
			if (piece->data[i][j] == BLOC)
			{
				check_mask = 0;
				if (consecutive_bloc(piece, i, j, &check_mask) == SIZE_PIECE)
					return (NONE);
				else
					return (FILE_INVALID);
			}
		}
	}
	return (FILE_INVALID);
}

static t_error	convert_piece(t_piece *piece, char *s)
{
	int		i;
	int		j;
	int		n;

	i = -1;
	while (++i < SIZE_PIECE)
	{
		j = -1;
		while (++j < SIZE_PIECE)
		{
			n = i * (SIZE_PIECE + 1) + j;
			if (s[n] != '#' && s[n] != '.')
				return (FILE_INVALID);
			piece->data[i][j] = s[n] == '#' ? BLOC : EMPTY;
		}
		if (s[i * (SIZE_PIECE + 1) + j] != '\n'
			&& s[i * (SIZE_PIECE + 1) + j] != '\0')
			return (FILE_INVALID);
	}
	return (is_valid_piece_four_consecutive(piece));
}

static t_error	read_loop(t_result *result, int fd)
{
	int		reader;
	int		buf_size = SIZE_PIECE * (SIZE_PIECE + 1) + 1;
	char	buffer[SIZE_PIECE * (SIZE_PIECE + 1) + 1];
	t_piece	piece;
	int		n;

	n = 0;
	while ((reader = read(fd, buffer, buf_size)) != 0)
	{
		buffer[reader] = '\0';
		exit_with_error(convert_piece(&piece, buffer));
		exit_with_error(add_piece_to_result(result, &piece, n++));
	}
	return (NONE);
}

t_error		file_to_pieces(t_result *result, char *file_name)
{
	int		fd;

	fd = open(file_name, O_RDONLY);
	if (fd < 0)
		return (READING_ERROR);
	return (read_loop(result, fd));
}
