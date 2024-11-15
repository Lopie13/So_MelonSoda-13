/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopie13 <lopie13@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 21:00:37 by mmata-al          #+#    #+#             */
/*   Updated: 2024/09/19 12:16:26 by lopie13          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*error_message(t_map *map)
{
	if (map->c == 0)
		return ("Error: missing 'C' element");
	else if (map->e == 0)
		return ("Error: missing 'E' element");
	else if (map->p == 0)
		return ("Error: missing 'P' element");
	else if (map->p > 1)
		return ("Error: there is more than one 'P' element");
	else if (map->e > 1)
		return ("Error: there is more than one 'E' element");
	return ("Error: missing map");
}

void	ft_message_error(t_vars *vars, int assets)
{
	write(1, "ERROR\n", 6);
	final_cleaner(vars, assets);
	exit(1);
}

void	ft_file_error(char *file)
{
	ft_printf("can't open %s, or it doesn't exist.\n", file);
	exit(1);
}

int	freemaplined(char *str)
{
	free(str);
	ft_printf("Error: invalid map! (multiple \\n found)");
	return (1);
}
