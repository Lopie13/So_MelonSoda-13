/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopie13 <lopie13@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/04 18:45:40 by mmata-al          #+#    #+#             */
/*   Updated: 2024/07/02 14:52:23 by lopie13          ###   ########.fr       */
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


void	flood_fill(char **map, int x, int y)
{
	int	w;
	int	h;

	w = 0;
	h = 0;
	while (map[h][w] != '\0' && map[h][w] != '\n')
		w++;
	while (map[h])
		h++;
	if (x < 0 || y < 0 || x >= w || y >= h)
		return ;
	if (map[y][x] == '1' || map[y][x] == 'F')
		return ;
	map[y][x] = 'F';
	flood_fill(map, (x + 1), y);
	flood_fill(map, (x - 1), y);
	flood_fill(map, x, (y - 1));
	flood_fill(map, x, (y + 1));
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
	assets_initiator(vars);
}

int	ft_exit(t_vars *vars)
{
	final_cleaner(vars, 1);
	exit(1);
	return (0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	invisible_door(t_vars *v, int x1, int y1)
{
	mlx_put_image_to_window(v->mlx, v->win, v->assets->ground->img, x1, y1);
	v->e_x = x1;
	v->e_y = y1;
}