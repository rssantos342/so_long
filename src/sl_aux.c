/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_aux.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:05:42 by ride-sou          #+#    #+#             */
/*   Updated: 2023/06/23 13:14:57 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	exit_error(t_game *so_long, char *msg)
{
	clean_game(so_long);
	ft_printf("Error\n");
	ft_printf("%s\n", msg);
	exit (EXIT_FAILURE);
}

int	ft_return_msg(t_game *so_long)
{
	if (so_long->player != 1)
		return (1);
	else if (so_long->exit != 1)
		return (2);
	else if (so_long->total_coins < 1)
		return (3);
	return (0);
}

int	flood_fill(int total_coins, int cur_y, int cur_x, char **map_draft)
{
	static int	coins = 0;
	static int	exit = 0;

	if (map_draft[cur_y][cur_x] == WALL)
		return (1);
	else if (map_draft[cur_y][cur_x] == COIN)
		coins++;
	else if (map_draft[cur_y][cur_x] == EXIT)
		exit++;
	map_draft[cur_y][cur_x] = WALL;
	flood_fill(total_coins, cur_y, cur_x + 1, map_draft);
	flood_fill(total_coins, cur_y, cur_x - 1, map_draft);
	flood_fill(total_coins, cur_y + 1, cur_x, map_draft);
	flood_fill(total_coins, cur_y - 1, cur_x, map_draft);
	if (coins == total_coins && exit == 1)
		return (0);
	else
		return (1);
}

int	check_filename(char *av)
{
	if (!ft_strnstr(&av[1], ".ber", ft_strlen(&av[1])))
	{	
		ft_printf("Invalid file extension. Try <map_name>.ber");
		return (0);
	}
	return (1);
}
