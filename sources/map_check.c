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

//Create a copy of the map to flood it and verify map completion.
void	map_path(t_game *game)
{
	char	**temp_map;

	temp_map = map_copy(game);
	//printf("P position[%i,%i]",game->map.player_pos.y,game->map.player_pos.x);
	if (!flood_fill(&game->map, game->map.player_pos, temp_map))
	{
		free_map(temp_map);
		error_handle("Map cannot be completed.", game);
	}
	free_map(temp_map);
}

//Check that the outline of the map is only '1'
void	map_enclosed(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.height)
	{
		if (game->map.map[i][0] != '1'
			|| game->map.map[i][game->map.width - 1] != '1')
			error_handle("Map is not enclosed", game);
		i++;
	}
	i = 0;
	while (i < game->map.width)
	{
		if (game->map.map[0][i] != '1'
			|| game->map.map[game->map.height - 1][i] != '1')
			error_handle("Map is not enclosed", game);
		i++;
	}
	return ;
}

//Check if the number of components is valid
void	components_check(t_game *game)
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
}
