/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:45:40 by mmata-al          #+#    #+#             */
/*   Updated: 2024/06/04 18:50:06 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	map_xloop(t_vars *vars, int x1, int y1, int map_y)
{
	int	map_x;

	map_x = 0;
	if (vars->map[map_y] == NULL)
	{
		final_cleaner(vars, 1);
		exit (1);
	}
	while (vars->win_w > 0)
	{
		put_image_to_map(vars->map[map_y][map_x], x1, y1, vars);
		vars->win_w--;
		map_x++;
		x1 += 32;
	}
	x1 = (map_x * 32);
	return (x1);
}

void	flood_checker(t_vars *vars, char **argv)
{
	//get_player(vars);
	flood_fill(vars->map, vars->x_p, vars->y_p);
	check_c(vars);
	check_e(vars);
	final_cleaner(vars, 0);
	vars->map = get_map(argv[1], vars);
	vars->assets = malloc(sizeof(t_assets));
	//assets_initiator(vars);
}

int	ft_exit(t_vars *vars)
{
	final_cleaner(vars, 1);
	exit(1);
	return (0);
}