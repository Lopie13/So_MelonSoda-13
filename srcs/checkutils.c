#include "so_long.h"


char	unknown_element(t_vars *v, char c)
{
	int	x;

	x = 0;
	while (v->map[x])
	{
		free(v->map[x]);
		x++;
	}
	free (v->map);
	ft_printf("Unknown element '%c'", c);
	exit (1);
}

t_map	map_ext(t_vars *vars, t_map map)
{
	while (map.y--)
	{
		map.x = 0;
		while (vars->map[map.y][map.x] != '\0')
		{
			if (vars->map[map.y][map.x] == 'E')
				map.e++;
			else if (vars->map[map.y][map.x] == 'P')
				map.p++;
			else if (vars->map[map.y][map.x] == 'C')
				map.c++;
			else if (vars->map[map.y][map.x] == 'L')
				map.l++;
			else if (vars->map[map.y][map.x] != '1' &&
				vars->map[map.y][map.x] != '0')
				unknown_element(vars, vars->map[map.y][map.x]);
			map.x++;
		}
	}
	return (map);
}

static char	*error_message(t_map *map)
{
	if (map->c == 0)
		return ("Error: missing 'C' element");
	else if (map->e == 0)
		return ("Error: missing 'E' element");
	else if (map->p == 0)
		return ("Error: missing 'P' element");
	else if (map->p > 1)
		return ("Error: there is more than one 'P' element");
	else if (map->l > 1)
		return ("Error: there is more than one 'L' element");
	else if (map->e > 1)
		return ("Error: there is more than one 'E' element");
	return ("Error: missing map");
}

void	check_elements(t_vars *vars)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.l = 0;
	map.y = get_height(vars->map);
	map = map_ext(vars, map);
/* 	if (map.l == 1)
		vars->lantern++; */
	if (map.e == 0 || map.p == 0 || map.c == 0 || map.p > 1
		|| map.l > 1 || map.e > 1)
		ft_error(vars, error_message(&map));
}