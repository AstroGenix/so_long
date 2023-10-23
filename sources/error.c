/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:17:06 by dberehov          #+#    #+#             */
/*   Updated: 2023/09/07 08:17:08 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//An easy way to print errors
void	error_handle(char *str, t_game *game)
{
	if (game)
		mlx_destroy(game);
	write(1, "\033[0;41m", 7);
	write(1, "Error", 5);
	write(1, "\033[0m\n", 5);
	write(1, "\033[0m", 4);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

void	free_texture(t_game *game)
{
	if (game->map.img_path.player)
		mlx_destroy_image(game->mlx_ptr, game->map.img_path.player);
	if (game->map.img_path.wall)
		mlx_destroy_image(game->mlx_ptr, game->map.img_path.wall);
	if (game->map.img_path.floor)
		mlx_destroy_image(game->mlx_ptr, game->map.img_path.floor);
	if (game->map.img_path.points)
		mlx_destroy_image(game->mlx_ptr, game->map.img_path.points);
	if (game->map.img_path.exit)
		mlx_destroy_image(game->mlx_ptr, game->map.img_path.exit);
	if (game->map.img_path.exit_open)
		mlx_destroy_image(game->mlx_ptr, game->map.img_path.exit_open);
	if (game->map.img_path.player_exit)
		mlx_destroy_image(game->mlx_ptr, game->map.img_path.player_exit);
}

//Clear struct variables
void	mlx_destroy(t_game *game)
{
	if (!game)
		return ;
	free_texture(game);
	if (game->window_ptr)
		mlx_destroy_window(game->mlx_ptr, game->window_ptr);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->map.map)
		free_map(game->map.map);
}

//Verify:
//The number of arguments
//If the map name is correct
//If the extension is correct
//If succeded opening the map
void	args_verify(int argn, char *args)
{
	int	fd;

	if (argn != 2)
		error_handle("Incorrect number of arguments.", NULL);
	if (ft_strlen(args) < 5)
		error_handle("Incorrect map name.", NULL);
	if (ft_strnstr(args, ".ber", 20) == NULL)
		error_handle("Incorrect extension.", NULL);
	fd = open(args, O_RDONLY);
	if (fd < 0)
		error_handle("Failed to open map.", NULL);
	close(fd);
}
