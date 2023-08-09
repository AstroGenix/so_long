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

//Open and read the map;
void	handle_err(int num)
{
	if (num == 0)
		write(1, "Invalid number of arguments.\n", 29);
	else if (num == 1)
		write(1, "Invalid map name/extension.\n", 28);
	exit(0);
}

//Check the map file [Might not need to be in this func]
void	check_map_args(const char *map)
{
	int	fd;

	if (ft_strnstr(map,".ber",20) == NULL)
		handle_err(1);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		handle_err(1);
	close(fd);
}

//Initialize the map
void	init_map(t_game *game)
{
	game->map.map = 0;
	game->map.player = 0;
	game->map.exit = 0;
	game->map.wall = 0;
	game->map.points = 0;
	game->map.width = WIDTH;
	game->map.heigth = HEIGTH;
}

//Create a border for the map
void	map_border(t_game *game, char *map)
{
	int		fd;
	char	*line;
	int		row;

	row = 0;
	fd = open(map, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			free(line);
			break ;
		}
		row++;
		free(line);
	}
	game->map.heigth = row;
	printf("Height: %i\n",row);
	close(fd);
}

//Check if map is allowed
void	verify_map(t_game *game, char *map)
{
	check_map_args(map);
	init_map(game);
	map_border(game, map);
}

int	main(int argn, char *args[])
{
	t_game	game;

	if (argn != 2)
		handle_err(0);
	verify_map(&game, args[1]);
	game.mlx = mlx_init();
	void	*mlx_win;

	mlx_win = mlx_new_window(game.mlx, WIDTH, HEIGTH, "So_Long");
	mlx_loop(game.mlx);
}
