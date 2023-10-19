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

//Verify the validity of the map
//NEED MAP TO BE FREED - in the exit of game func
void	map_verify(t_game *game, char *map)
{
	map_border(game, map);
	if (game->map.height < 3 || game->map.width < 3)
		error_handle("Incorrect map size.", game);
	game->map.map = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.map)
		error_handle("Map allocation failed.", game);
	map_build(game, map);
	components_check(game);
	map_enclosed(game);
	map_path(game);
}

int	main(int argn, char *args[])
{
	t_game	game;

	args_verify(argn, args[1]);
	ft_memset(&game, 0, sizeof(t_game));
	map_verify(&game, args[1]);
	game.mlx_ptr = mlx_init();
	if (!game.mlx_ptr)
		error_handle("Couldn't initialize the game.", &game);
	//printf("Player: %i\n", game.map.player);
	//printf("Exit: %i\n", game.map.exit);
	//printf("Points: %i\n", game.map.points);
	//printf("Map %ix%i\n", game.map.width, game.map.height);
	game.window_ptr = mlx_new_window(game.mlx_ptr, game.map.width * IMG, \
	game.map.height * IMG, "So Longer");
	if (!game.window_ptr)
		error_handle("Couldn't generate a window.", &game);
	mlx_loop(game.mlx_ptr);
	free (game.mlx_ptr);
	return (0);
}
