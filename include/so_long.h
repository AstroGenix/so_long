/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:02:14 by dberehov          #+#    #+#             */
/*   Updated: 2023/08/08 11:02:15 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

//Needed Libraries
# include <fcntl.h>
# include <stdbool.h>
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

//Player current location struct
typedef struct	s_player
{
	int x;
	int y;
}				t_player;

//File path for the images
typedef struct s_img_path
{
	char	*player;
	char	*wall;
	char	*floor;
	char	*points;
	char	*exit;
	char	*exit_open;
	char	*player_exit;
}				t_img_path;

//Map struct
typedef struct	s_map
{
	char		**map;
	int			player;
	int			wall;
	int			floor;
	int			points;
	int			exit;
	int			width;
	int			height;
	t_player	player_pos;
	t_img_path	img_path;
}				t_map;

//Game struct
typedef struct	s_game
{
	void		*mlx_ptr;//    MLX pointer
	void		*window_ptr;// MLX window pointer
	int			steps;//	   Step counter
	t_map		map;//		   Map struct
}				t_game;

//Define key presses
# define UP		65362
# define DN		65364
# define LT		65361
# define RT		65363
# define W		119
# define A		97
# define S		115
# define D		100
# define ESC	65307

//Error handling functions
void		error_handle(char *str, t_game *game);
void		mlx_destroy(t_game *game);
void		free_map(char **map);

//Verify initial string
void		args_verify(int argn, char *args);

//Map verification
void		map_build(t_game *game, char *map);
void		map_border(t_game *game, char *map);
void		components_check(t_game *game);
void		map_enclosed(t_game *game);

//Map verification - utils
char		**map_copy(t_game *game);
void		map_path(t_game *game);
bool		flood_fill(t_map *map, t_player cur, char **cell);
void		find_component(t_game *game, char to_find);

//
void		xpm_init(t_game *game);
void		xpm_open(t_game *game);
void		xpm_check(t_game *game);
void		map_draw(t_game *game, char comp, int y, int x);

//
void		start_game(t_game *game);

#endif
