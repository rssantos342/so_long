/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:04:42 by ride-sou          #+#    #+#             */
/*   Updated: 2023/06/23 17:08:51 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	create_map(t_game *so_long, char *file)
{
	int	fd;

	get_rows(so_long, file);
	so_long->map = ft_calloc(so_long->rows + 1, sizeof(char *));
	if (!so_long->map)
		exit_error(so_long, "Couldn't create so_long->map.");
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(so_long, "Couldn't open requested file.");
	read_map(so_long, fd);
	close (fd);
}

void	get_rows(t_game *so_long, char *file)
{
	int		fd;
	char	*line;

	so_long->rows = 0;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		exit_error(so_long, "Couldn't open the requested file.");
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		free(line);
		so_long->rows++;
	}
	close(fd);
}

void	read_map(t_game *so_long, int fd)
{
	int		i;
	char	*line;

	i = -1;
	while (++i < so_long->rows)
	{
		line = get_next_line(fd);
		if (!line)
			exit_error(so_long, "Couldn't read map.");
		so_long->map[i] = ft_strtrim(line, "\n");
		if (!so_long->map[i])
			exit_error(so_long, "Couldn't read map.");
		free(line);
	}
}
