/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dberehov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 08:17:06 by dberehov          #+#    #+#             */
/*   Updated: 2023/09/07 08:17:08 by dberehov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

//An easy way to print errors
void	error_handle(char *str)
{
	write(1, "\033[0;41m", 7);
	write(1, "Error", 5);
	write(1, "\033[0m\n", 5);
	write(1, "\033[0m", 4);
	write(1, str, ft_strlen(str));
	write(1, "\n", 1);
	exit(1);
}

/* Verify:
- The number of arguments;
- If the map name is correct;
- If the extension is correct:
- If succeded opening the map.
*/
void	verify_args(int argn, char *args)
{
	int	fd;

	if (argn != 2)
		error_handle("Incorrect number of arguments.");
	if (ft_strlen(args) < 5)
		error_handle("Incorrect map name.");
	if (ft_strnstr(args,".ber",20) == NULL)
		error_handle("Incorrect extension.");
	fd = open(args, O_RDONLY);
	if (fd < 0)
		error_handle("Failed to open map.");
	close(fd);
}
