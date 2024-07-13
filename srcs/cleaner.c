
#include "so_long.h"

void	final_cleaner(t_vars *vars, int assets)
{
	int	i;

	i = 0;
	while (vars->map && vars->map[i] != NULL)
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
	if (assets == 1)
	{
		assets_cleaner(vars);
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
	else if (assets == 2)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		mlx_destroy_display(vars->mlx);
		free(vars->mlx);
	}
}

void	exit_door(t_vars *v)
{
	final_cleaner(v, 1);
	exit(1);
}