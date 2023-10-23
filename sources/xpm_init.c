/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:05:34 by dberehov          #+#    #+#             */
/*   Updated: 2023/10/23 14:05:35 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Get the path to images into the variables
void	xpm_open(t_game *game)
{
	int	i;

	i = 32;
	game->map.img_path.player = mlx_xpm_file_to_image(game->mlx_ptr,
									"textures/player.xpm", &i, &i);
	game->map.img_path.wall = mlx_xpm_file_to_image(game->mlx_ptr,
									"textures/wall.xpm", &i, &i);
	game->map.img_path.floor = mlx_xpm_file_to_image(game->mlx_ptr,
									"textures/floor.xpm", &i, &i);
	game->map.img_path.points = mlx_xpm_file_to_image(game->mlx_ptr,
									"textures/points.xpm", &i, &i);
	game->map.img_path.exit = mlx_xpm_file_to_image(game->mlx_ptr,
									"textures/exit.xpm", &i, &i);
	game->map.img_path.exit_open = mlx_xpm_file_to_image(game->mlx_ptr,
									"textures/e_open.xpm", &i, &i);
	game->map.img_path.player_exit = mlx_xpm_file_to_image(game->mlx_ptr,
									"textures/p_exit.xpm", &i, &i);
}

//Make sure the images opened
void	xpm_check(t_game *game)
{
	if (!game->map.img_path.player)
		error_handle("Failed to open player image", game);
	if (!game->map.img_path.wall)
		error_handle("Failed to open wall image", game);
	if (!game->map.img_path.floor)
		error_handle("Failed to open floor image", game);
	if (!game->map.img_path.points)
		error_handle("Failed to open points image", game);
	if (!game->map.img_path.exit)
		error_handle("Failed to open exit image", game);
	if (!game->map.img_path.exit_open)
		error_handle("Failed to open open exit image", game);
	if (!game->map.img_path.player_exit)
		error_handle("Failed to open player on exit image", game);
}

void	map_draw(t_game *game, char comp, int y, int x)
{
	if (comp == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.wall, 32 * y, 32 * x);
	else if (comp == '0')
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.floor, 32 * y, 32 * x);
	else if (comp == 'P')
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.player, 32 * y, 32 * x);
	else if (comp == 'C')
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.points, 32 * y, 32 * x);
	else if (comp == 'E')
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.exit, 32 * y, 32 * x);
	else if (comp == 'p')
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.player_exit, 32 * y, 32 * x);
	else if (comp == 'e')
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.exit_open, 32 * y, 32 * x);
}

void	xpm_init(t_game *game)
{
	int	i;
	int	j;

	xpm_open(game);
	xpm_check(game);
	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			map_draw(game, game->map.map[i][j], j, i);
			j++;
		}
		i++;
	}
}
