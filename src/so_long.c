/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 12:52:14 by ride-sou          #+#    #+#             */
/*   Updated: 2023/06/28 15:23:40 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	start_game(char *file)
{
	t_game	so_long;

	ft_bzero(&so_long, sizeof(t_game));
	create_map(&so_long, file);
	check_map(&so_long);
	start_mlx(&so_long);
	load_sprites(&so_long);
	render_map(&so_long);
	mlx_hook(so_long.win, ON_KEYPRESS, KEYPRESS_MASK, check_keypress, &so_long);
	mlx_hook(so_long.win, ON_CLOSE, CLOSE_MASK, quit_game, &so_long);
	mlx_loop(so_long.mlx);
}

int	main(int ac, char **av)
{
	if (ac != 2)
	{
		ft_printf("Wrong number of arguments.\nTry ./so_long <map>\n");
		return (1);
	}
	else
	{
		if (!check_filename(av[1]))
			start_game(av[1]);
		else
			return (1);
	}
}
