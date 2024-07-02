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
			else if (vars->map[map.y][map.x] != '1' &&
				vars->map[map.y][map.x] != '0')
				unknown_element(vars, vars->map[map.y][map.x]);
			map.x++;
		}
	}
	return (map);
}

void	check_elements(t_vars *vars)
{
	t_map	map;

	map.c = 0;
	map.p = 0;
	map.e = 0;
	map.y = get_height(vars->map);
	map = map_ext(vars, map);
	if (map.e == 0 || map.p == 0 || map.c == 0 || map.p > 1
		|| map.e > 1)
		ft_error(vars, error_message(&map));
}


int	check_c(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][n] != '\0' && vars->map[i][n] != '\n')
		{
			n++;
			if (vars->map[i][n - 1] == 'C')
			{
				ft_printf("Error!");
				final_cleaner(vars, 2);
				exit(1);
			}
		}
		n = 0;
		i++;
	}
	vars->map[0][0] = 1;
	return (1);
}

int	check_e(t_vars *vars)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (vars->map[i])
	{
		while (vars->map[i][n] != '\0' && vars->map[i][n] != '\n')
		{
			n++;
			if (vars->map[i][n] == 'E')
			{
				ft_printf("Error!");
				final_cleaner(vars, 2);
				exit(1);
			}
		}
		n = 0;
		i++;
	}
	vars->map[0][0] = 1;
	return (1);
}