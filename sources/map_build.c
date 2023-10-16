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

// Count collectibles and others.
// Error for illegal chars.
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
	check_components(game);
}

char	*trim_nbreak(char *str, const char *cut)
{
	char	*trim_str;
	int		end;
	
	if (!str || !cut)
		return (NULL);
	end = ft_strlen(str);
	while (end > 0 && str[end - 1] == '\n')
		end--;
	trim_str = malloc(sizeof(char) * (end + 1));
	if (!trim_str)
		return (NULL);
	ft_strlcpy(trim_str, str, end);
	//Test to see if the string gets correctly trimmed
	//printf("String: \"%s\"\n", str);
	//printf("Trimmed: \"%s\"\n", trim_str);
	free(str);
	return (trim_str);
}

//Get map contents into map variable
void	map_build(t_game *game, char *map)
{
	int	fd;
	int	i;

	fd = open(map, O_RDONLY);
	i = 0;
	while (i < game->map.height)
	{
		game->map.map[i] = get_next_line(fd);
		count_components(game->map.map[i], game);
		i++;
	}
	game->map.map[i] = NULL;
	close(fd);
	i = 0;
	while (i < (game->map.height) - 1)
	{
		game->map.map[i] = trim_nbreak(game->map.map[i], "\n");
		if (!game->map.map[i])
			error_handle("Error in removing new line from map.", game);
		i++;
	}
}
