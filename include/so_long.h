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
# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"

//Map struct
typedef struct	s_map
{
	char	**map;
	int		player;
	int		wall;
	int		points;
	int		exit;
	int		width;
	int		heigth;
}				t_map;
//Player struct
typedef struct	s_player
{
	int x;
	int y;
}				t_player;

//Game struct
typedef struct	s_game
{
	void		*mlx;
	t_map		map;
	t_player	player_pos;
}				t_game;

//Define for windows size
# define WIDTH	1600
# define HEIGTH	800

//Define key presses
# define UP		65362
# define DOWN	65364
# define LEFT	65361
# define RIGHT	65363
# define W		119
# define A		97
# define S		115
# define D		100
# define ESC	65307

#endif
