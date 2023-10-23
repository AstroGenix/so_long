/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 14:04:51 by dberehov          #+#    #+#             */
/*   Updated: 2023/10/23 14:04:54 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_player(t_game *game)
{
	printf("moved\n");
}

int	quit_game(t_game *game)
{
	mlx_destroy(game);
	exit(0);
	return (0);
}

int	key_press(int key, t_game *game)
{
	if (key == ESC)
		quit_game(game);
	else if (key == W || key == UP)
		move_player(game);
	else if (key == A || key == LT)
		move_player(game);
	else if (key == S || key == DN)
		move_player(game);
	else if (key == D || key == RT)
		move_player(game);
	return (0);
}

void	start_game(t_game *game)
{
	mlx_hook(game->window_ptr, 2, (1L<<0), key_press, game);//Keypress event
	mlx_hook(game->window_ptr, 17, (1L<<17), quit_game, game);//Destroy event
	mlx_loop(game->mlx_ptr);
}