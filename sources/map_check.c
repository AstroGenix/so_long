/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 14:42:57 by dberehov          #+#    #+#             */
/*   Updated: 2023/10/11 14:42:58 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	map_enclosed(t_map *map)
{
		int	i;

	i = 0;
	while (i < map->height)
	{
		if (map->map[i][0] != '1' || map->map[i][map->width - 1] != '1')
			return (false);
		i++;
	}
	i = 0;
	while (i < map->width)
	{
		if (map->map[0][i] != '1' || map->map[map->height - 1][i] != '1')
			return (false);
			i++;
	}
	return (true);
}

//Check if the number of components is valid.
void	check_components(t_game *game)
{
	if (game->map.player == 0 || game->map.player > 1)
		error_handle("Invalid map: No starting position or too many", game);
	else if (game->map.points == 0)
		error_handle("Invalid map: No collectibles found.", game);
	else if (game->map.exit == 0 || game->map.exit > 1)
		error_handle("Invalid map: No exit or too many", game);
}

//Get the max sizes for the map border
//Check if the map size is at least 3 in height or width
void	map_border(t_game *game, char *map)
{
	int		fd;
	char	*line;
	int		i;
	int		min;

	min = -1;
	fd = open(map, O_RDONLY);
	line = get_next_line(fd);
	while (line != NULL)
	{
		i = 0;
		while (line[i] != '\0' && line[i] != '\n')
			i++;
		if (min == -1)
			min = i;
		else if (min != i)
			error_handle("Incorrect map size.", game);
		game->map.width = i;
		game->map.height++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	if (game->map.height < 3 || game->map.width < 3)
		error_handle("Incorrect map size.", game);
}
