/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:05:14 by ride-sou          #+#    #+#             */
/*   Updated: 2023/06/23 13:26:27 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	move_player(t_game *so_long)
{
	static int	flag = 0;

	if (flag == 1)
	{
		so_long->map[so_long->curr.y][so_long->curr.x] = PLAYER;
		so_long->map[so_long->prev.y][so_long->prev.x] = EXIT;
		flag = 0;
	}
	else if (so_long->map[so_long->curr.y][so_long->curr.x] == EXIT)
	{
		so_long->map[so_long->prev.y][so_long->prev.x] = SPACE;
		flag = 1;
	}
	else
		so_long->map[so_long->prev.y][so_long->prev.x] = SPACE;
	so_long->map[so_long->curr.y][so_long->curr.x] = PLAYER;
	render_tile(so_long, so_long->prev.x, so_long->prev.y);
	render_tile(so_long, so_long->curr.x, so_long->curr.y);
}

int	check_keypress(int key, t_game *so_long)
{
	so_long->prev.y = so_long->curr.y;
	so_long->prev.x = so_long->curr.x;
	if (key == ESC)
		quit_game(so_long);
	else if (key == W || key == UP)
		so_long->curr.y--;
	else if (key == S || key == DOWN)
		so_long->curr.y++;
	else if (key == A || key == LEFT)
		so_long->curr.x--;
	else if (key == D || key == RIGHT)
		so_long->curr.x++;
	if (so_long->map[so_long->curr.y][so_long->curr.x] != WALL)
	{
		ft_no_wall(key, so_long);
	}
	else
	{
		so_long->curr.y = so_long->prev.y;
		so_long->curr.x = so_long->prev.x;
	}
	return (key);
}

void	ft_no_wall(int key, t_game *so_long)
{
	if (key == W || key == A || key == D || key == S \
		|| key == UP || key == DOWN || key == LEFT || key == RIGHT)
		ft_printf("Number of moves: %i\n", ++so_long->moves);
	if (so_long->map[so_long->curr.y][so_long->curr.x] == COIN)
		so_long->coins++;
	else if (so_long->map[so_long->curr.y][so_long->curr.x] == EXIT \
				&& so_long->coins == so_long->total_coins)
	{
		ft_printf("\n#TUDONOSSONADADELES\n\n");
		quit_game(so_long);
	}
	move_player(so_long);
}
