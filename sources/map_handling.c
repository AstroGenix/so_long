/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_handling.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:17:15 by dberehov          #+#    #+#             */
/*   Updated: 2023/09/07 08:17:17 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

/*Flood Fill - Check if map is possible
- The player needs access to the exit.
- The player, prior to exiting the map, is able to collect all collectables.
*/

/*Check the map.
- Only one exit.
- Map is surrounded by walls.
- Only one starting position.
- At least one collectible.
- Is rectangular.
- - Go into floodfill.
*/