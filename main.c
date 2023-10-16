/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 11:02:30 by dberehov          #+#    #+#             */
/*   Updated: 2023/08/08 11:02:32 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/so_long.h"

//Check if map is allowed
//NEED MAP TO BE FREED
void	map_verify(t_game *game, char *map)
{
	map_border(game, map);
	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	map_build(game, map);
	//map_check_components(game);
	/*if (set_map_layout(game, map) < 0)
	- Loop map.heigth to join
	- Count ammount of player,exit,collectible
	- Check the count
	- Loop str to get map.width
	- Malloc the heigth and write to it content of str*/
}

int	main(int argn, char *args[])
{
	t_game	game;

	verify_args(argn, args[1]);
	ft_memset(&game, 0, sizeof(t_game));
	map_verify(&game, args[1]);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		error_handle("Couldn't initialize the game.", &game);
	//printf("Player: %i\n", game.map.player);
	//printf("Collectible(s): %i\n", game.map.points);
	//printf("Exit: %i\n", game.map.exit);
	//printf("Floors: %i\n", game.map.floor);
	game.window_ptr = mlx_new_window(game.mlx_ptr, game.map.width * IMG, \
	game.map.height * IMG, "So Longer");
	if (!game.window_ptr)
		error_handle("Couldn't generate a window.", &game);
	//mlx_loop_hook(game.mlx,)
	mlx_loop(game.mlx_ptr);
	free (game.mlx_ptr);
	return (0);
}
