/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_graphics.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:04:59 by ride-sou          #+#    #+#             */
/*   Updated: 2023/06/28 16:12:13 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_mlx(t_game *so_long)
{
	so_long->mlx = mlx_init();
	if (!so_long->mlx)
		exit_error(so_long, "Failed to initialize mlx.");
	so_long->win = mlx_new_window(so_long->mlx, \
			so_long->cols * SIZE, so_long->rows * SIZE, "so_long");
	if (!so_long->win)
		exit_error(so_long, "Failed to create window.");
}

void	load_sprites(t_game *so_long)
{
	so_long->sp = malloc(SPRITES * sizeof(t_sprite));
	if (!so_long->sp)
		exit_error(so_long, "Failed to allocate memory on sprites.");
	so_long->sp[W1].img = mlx_xpm_file_to_image(so_long->mlx, FW1, \
			&(so_long->sp[W1].width), &(so_long->sp[W1].height));
	so_long->sp[S1].img = mlx_xpm_file_to_image(so_long->mlx, FS1, \
			&(so_long->sp[S1].width), &(so_long->sp[S1].height));
	so_long->sp[C1].img = mlx_xpm_file_to_image(so_long->mlx, FC1, \
			&(so_long->sp[C1].width), &(so_long->sp[C1].height));
	so_long->sp[E1].img = mlx_xpm_file_to_image(so_long->mlx, FE1, \
			&(so_long->sp[E1].width), &(so_long->sp[E1].height));
	so_long->sp[P1].img = mlx_xpm_file_to_image(so_long->mlx, FP1, \
			&(so_long->sp[P1].width), &(so_long->sp[P1].height));
}

void	render_tile(t_game *so_long, int x, int y)
{
	if (so_long->map[y][x] == WALL)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sp[W1].img, so_long->sp[W1].width * x, \
		so_long->sp[W1].height * y);
	else if (so_long->map[y][x] == COIN)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sp[C1].img, so_long->sp[C1].width * x, \
		so_long->sp[C1].height * y);
	else if (so_long->map[y][x] == EXIT)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sp[E1].img, so_long->sp[E1].width * x, \
		so_long->sp[E1].height * y);
	else if (so_long->map[y][x] == SPACE)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sp[S1].img, so_long->sp[S1].width * x, \
		so_long->sp[S1].height * y);
	else if (so_long->map[y][x] == PLAYER)
		mlx_put_image_to_window(so_long->mlx, so_long->win, \
		so_long->sp[P1].img, so_long->sp[P1].width * x, \
		so_long->sp[P1].height * y);
}

void	render_map(t_game *so_long)
{
	int	x;
	int	y;

	y = -1;
	while (++y < so_long->rows)
	{
		x = -1;
		while (++x < so_long->cols)
			render_tile(so_long, x, y);
	}
}
