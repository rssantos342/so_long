/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_clean_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 15:04:29 by ride-sou          #+#    #+#             */
/*   Updated: 2023/06/23 13:17:11 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	clean_map_draft(char **map_draft)
{
	int	i;

	i = 0;
	if (!map_draft)
		return ;
	while (map_draft[i])
		free (map_draft[i++]);
	free (map_draft);
}

void	clean_map(t_game *so_long)
{
	int	i;

	i = 0;
	if (!so_long->map)
		return ;
	while (so_long->map[i])
		free (so_long->map[i++]);
	free (so_long->map);
}

void	clean_sprites(t_game *so_long)
{
	int	i;

	i = -1;
	while (++i < SPRITES)
		mlx_destroy_image(so_long->mlx, so_long->sp[i].img);
	free(so_long->sp);
}

void	clean_game(t_game *so_long)
{
	if (!so_long)
		return ;
	if (so_long->map)
		clean_map(so_long);
	if (so_long->sp)
		clean_sprites(so_long);
	if (so_long->win)
		mlx_destroy_window(so_long->mlx, so_long->win);
	if (so_long->mlx)
		mlx_destroy_display(so_long->mlx);
	free(so_long->mlx);
}

int	quit_game(t_game *so_long)
{
	clean_game(so_long);
	exit(EXIT_SUCCESS);
}
