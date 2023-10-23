/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <dberehov@student.42porto.co      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 08:35:47 by dberehov          #+#    #+#             */
/*   Updated: 2023/10/19 08:35:49 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Returns the coordinates of where the player is at
void	find_player(t_game *game)
{
	t_player	pos;

	pos.y = 0;
	while (game->map.map[pos.y])
	{
		pos.x = 0;
		while (game->map.map[pos.y][pos.x])
		{
			if (game->map.map[pos.y][pos.x] == 'P')
			{
				game->map.player_pos = (t_player){pos.x, pos.y};
				return ;
			}
			pos.x++;
		}
		pos.y++;
	}
	error_handle("Could not find component.", game);
}

//Free each line of map
void	free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		map[i] = NULL;
		i++;
	}
	if (i > 0)
		free (map);
	map = NULL;
}

//Create a temporary copy of the map for flooding
char	**map_copy(t_game *game)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = ft_calloc((game->map.height + 1), sizeof(char *));
	if (!new_map)
		error_handle("Failed to allocate temporary map. [map_copy()]", game);
	while (i < game->map.height)
	{
		new_map[i] = ft_strdup(game->map.map[i]);
		if (!new_map[i])
		{
			free_map(new_map);
			error_handle("Failed to copy to new map. [map_copy()]", game);
		}
		i++;
	}
	return (new_map);
}

//Through recursion fill the floor to make sure coins and
//exit can be collected.
bool	flood_fill(t_map *map, t_player cur, char **cell)
{
	static int	points = 0;
	static bool	exit = false;

	if (cell[cur.y][cur.x] == '1')
		return (false);
	else if (cell[cur.y][cur.x] == 'C')
		points++;
	else if (cell[cur.y][cur.x] == 'E')
		exit = true;
	cell[cur.y][cur.x] = '1';
	flood_fill(map, (t_player){cur.x + 1, cur.y}, cell);
	flood_fill(map, (t_player){cur.x - 1, cur.y}, cell);
	flood_fill(map, (t_player){cur.x, cur.y + 1}, cell);
	flood_fill(map, (t_player){cur.x, cur.y - 1}, cell);
	return (exit && points == map->points);
}
