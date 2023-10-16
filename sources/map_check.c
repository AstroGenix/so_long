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
