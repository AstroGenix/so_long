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
	map_border(game, map);
}

int	main(int argn, char *args[])
{
	t_game	game;

	verify_args(argn, args[1]);
	ft_memset(&game, 0, sizeof(t_game));
	verify_map(&game, args[1]);
	game.mlx = mlx_init();
	void	*mlx_win;

	mlx_win = mlx_new_window(game.mlx, WIDTH, HEIGTH, "So_Long");
	mlx_loop(game.mlx);
}
