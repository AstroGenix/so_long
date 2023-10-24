/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_build.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 10:06:47 by dberehov          #+#    #+#             */
/*   Updated: 2023/09/07 10:06:49 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//Finds player x,y coordinate and saves them in the struct
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

//Count collectibles and others
//Catch illegal characters
void	count_components(char *str, t_game *game)
{
	int	i;

	i = 0;
	while (i < game->map.width && str[i] != '\n')
	{
		if (str[i] == '0')
			game->map.floor += 1;
		else if (str[i] == '1')
			game->map.wall += 1;
		else if (str[i] == 'C')
			game->map.points += 1;
		else if (str[i] == 'E')
			game->map.exit += 1;
		else if (str[i] == 'P')
			game->map.player += 1;
		else
			error_handle("Map contains illegal characters.", game);
		i++;
	}
}

//Remove the new line from the string
char	*rem_nline(char *str, const char *cut)
{
	char	*trim_str;
	int		end;

	if (!str || !cut)
		return (NULL);
	end = ft_strlen(str);
	while (end > 0 && str[end] == '\n')
		end--;
	trim_str = malloc(sizeof(char) * (end + 1));
	if (!trim_str)
		return (NULL);
	ft_strlcpy(trim_str, str, end);
	free(str);
	return (trim_str);
}

//Get map text into map variable
//Count components in each line (x) of map
//Get x,y coordinates of player
//Remove '\n' from map text
void	map_build(t_game *game, char *map)
{
	int			fd;
	int			i;

	fd = open(map, O_RDONLY);
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[i] = get_next_line(fd);
		count_components(game->map.map[i], game);
		i++;
	}
	game->map.map[i] = NULL;
	find_player(game);
	close(fd);
	i = 0;
	while (i < (game->map.height) - 1)
	{
		game->map.map[i] = rem_nline(game->map.map[i], "\n");
		if (!game->map.map[i])
			error_handle("Error in removing new line from map.", game);
		i++;
	}
}
