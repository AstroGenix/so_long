/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:00:17 by dberehov          #+#    #+#             */
/*   Updated: 2023/10/23 15:00:19 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	transition_player(t_game *game)
{
	t_player	pos;

	pos.y = game->map.player_pos.y;
	pos.x = game->map.player_pos.x;
	if (game->map.map[pos.y][pos.x] == 'E')
	{
			mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.exit, 32 * pos.x, 32 * pos.y);
	}
	else
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.floor, 32 * pos.x, 32 * pos.y);
	}
}

void	get_destination(t_game *game)
{
	t_player	pos;

	pos.y = game->map.player_pos.y;
	pos.x = game->map.player_pos.x;
	if (game->map.map[pos.y][pos.x] == 'E' && game->map.points > 0)
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.p_exit, 32 * game->map.player_pos.x, 32 * game->map.player_pos.y);
	else if (game->map.map[pos.y][pos.x] == 'C')
	{
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.player, 32 * game->map.player_pos.x, 32 * game->map.player_pos.y);
		game->map.map[pos.y][pos.x] = '0';
		game->map.points--;
	}
	else if (game->map.map[pos.y][pos.x] == 'E' && game->map.points == 0)
		quit_game(game);
	else
		mlx_put_image_to_window(game->mlx_ptr, game->window_ptr, game->map.img_path.player, 32 * game->map.player_pos.x, 32 * game->map.player_pos.y);
}
//
void	move_player(t_game *game, int y, int step)
{
	if (y == 1)//up || down
	{
		if (move_into_wall(&game->map, y, step))
			return ;
		transition_player(game);
		game->map.player_pos.x += step;
	}
	else//left || right
	{
		if (move_into_wall(&game->map, y, step))
			return ;
		transition_player(game);
		game->map.player_pos.y += step;
	}
	get_destination(game);
	output_moves(game);
}
