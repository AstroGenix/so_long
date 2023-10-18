#include "../include/so_long.h"

//Might want to change t_game to t_map
// Might not need to create var pos since pos is in map.
t_player	find_component(t_game *game, char to_find)
{
	t_player	pos;

	pos.y = 0;
	while (game->map.map[pos.y])
	{
		pos.x = 0;
		while (game->map.map[pos.y][pos.x])
		{
			if (game->map.map[pos.y][pos.x] == to_find)
				return (pos);
			pos.x++;
		}
		pos.y++;
	}
	error_handle("Component missing.", game);
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
		free(map[i])
		map[i] = NULL;
		i++;
	}
	map = NULL;
}
/* PART 2 TEST
//Create a temporary copy of the map for flooding
char	**map_copy(t_game *game)
{
	int		i;
	char	**new_map;

	i = 0;
	new_map = (char **)malloc(sizeof(char *) * (game->map.height + 1));
	if (!new_map)
		error_handle("Failed to allocate temporary map. [map_copy()]", game);
	while (i < game->map.height)
	{
		new_map[i] = ft_strdup(game->map.map[i]);
		if (new_map[i])
		{
			free_map(new_map);
			error_handle("Failed to copy to new map. [map_copy()]", game);
		}
		i++;
	}
	return (new_map);
}

//NEEDS THOUROUGH TESTING
bool	flood_fill(t_map *map, t_player cur, char **cell)
{
	static int	points;
	static int	exit;

	if (cell[cur.y][cur.x] == '1')
		return (false);
	else if (cell[cur.y][cur.x] == 'C')
		coins++;
	else if (cell[cur.y][cur.x] == 'E')
		exit = true;
	cell[cur.y][cur.x] == '1';
	flood_fill(map, (t_player){cur.x + 1, cur.y}, cell);
	flood_fill(map, (t_player){cur.x - 1, cur.y}, cell);
	flood_fill(map, (t_player){cur.x, cur.y + 1}, cell);
	flood_fill(map, (t_player){cur.x, cur.y - 1}, cell);
	return (points == map->points && exit);
}
*/