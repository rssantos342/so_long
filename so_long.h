/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ride-sou <ride-sou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 14:30:55 by ride-sou          #+#    #+#             */
/*   Updated: 2023/06/28 16:46:26 by ride-sou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"

# define SIZE		32
# define SPRITES	5

# define FW1	"sprites/1.xpm"
# define FS1	"sprites/0.xpm"
# define FC1	"sprites/c.xpm"
# define FE1	"sprites/e.xpm"
# define FP1	"sprites/p.xpm"

# define SPACE	'0'
# define WALL	'1'
# define COIN	'C'
# define EXIT	'E'
# define PLAYER	'P'

# define W1	0
# define S1	1
# define C1	2
# define E1	3
# define P1	4

# define ESC	65307
# define W		119
# define A		97
# define S		115
# define D		100
# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363

# define ON_KEYPRESS	2
# define ON_CLOSE		17

typedef enum e_mask
{
	KEYPRESS_MASK	= (1L << 0),
	CLOSE_MASK		= (1L << 17),
}					t_mask;

typedef struct s_point
{
	int	x;
	int	y;
}			t_point;

typedef struct s_sprite
{
	void	*img;
	int		height;
	int		width;
}			t_sprite;

typedef struct s_game
{
	t_point		curr;
	t_point		prev;
	t_sprite	*sp;
	char		**map;
	void		*mlx;
	void		*win;
	int			coins;
	int			exit;
	int			total_coins;
	int			player;
	int			moves;
	int			rows;
	int			cols;
}					t_game;

//sl_aux.c
int		exit_error(t_game *so_long, char *msg);
int		ft_return_msg(t_game *so_long);
int		flood_fill(int total_coins, int cur_y, int cur_x, char **map_draft);
int		check_filename(char *str);
//sl_check_map.c
int		check_format(t_game *so_long);
int		check_walls(t_game *so_long);
int		check_sprites(t_game *so_long);
int		check_paths(t_game *so_long);
void	check_map(t_game *so_long);
// sl_clean_exit.c
void	clean_map_draft(char **map_draft);
void	clean_map(t_game *so_long);
void	clean_sprites(t_game *so_long);
void	clean_game(t_game *so_long);
int		quit_game(t_game *so_long);
// sl_create_map.c
void	create_map(t_game *so_long, char *file);
void	get_rows(t_game *so_long, char *file);
void	read_map(t_game *so_long, int fd);
// sl_graphics.c
void	start_mlx(t_game *so_long);
void	load_sprites(t_game *so_long);
void	render_tile(t_game *so_long, int x, int y);
void	render_map(t_game *so_long);
// sl_moves.c
void	move_player(t_game *so_long);
int		check_keypress(int key, t_game *so_long);
void	ft_no_wall(int key, t_game *so_long);
// so_long.c
void	start_game(char *file);

#endif