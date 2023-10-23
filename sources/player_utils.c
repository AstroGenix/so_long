/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:15:47 by dberehov          #+#    #+#             */
/*   Updated: 2023/10/23 15:15:48 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

bool	move_into_wall(t_map *map, int y, int step)
{
	if (map->map[map->player_pos.y][map->player_pos.x + step] == '1' && y == 1)
		return (true);
	else if (map->map[map->player_pos.y + step][map->player_pos.x] == '1' && y == 0)
		return (true);
	else
		return (false);
}

//
void	output_moves(t_game *game)
{
	char	*i;

	game->steps++;
	i = ft_itoa(game->steps);
	write(1, "Steps: ", 7);
	write(1, i, ft_strlen(i));
	write(1, "\n", 1);
	free(i);
}
