/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopie13 <lopie13@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:28:28 by mmata-al          #+#    #+#             */
/*   Updated: 2024/08/01 11:47:31 by lopie13          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int keycode, t_vars *vars)
{
	if (keycode == XK_d)
		move_right(vars);
	else if (keycode == XK_a)
		move_left(vars);
	else if (keycode == XK_w)
		move_up(vars);
	else if (keycode == XK_s)
		move_down(vars);
	else if (keycode == XK_Escape)
	{
		final_cleaner(vars, 1);
		exit(1);
	}
	return (0);
}

void	render_map(t_vars *vars, char **argv)
{
	int	map_y;
	int	y1;
	int	backup_w;

	map_y = 0;
	y1 = 0;
	backup_w = vars->win_w;
	flood_checker(vars, argv);
	while (vars->win_h > 0)
	{
		map_xloop(vars, 0, y1, map_y);
		vars->win_w = backup_w;
		map_y++;
		vars->win_h--;
		y1 = (map_y * 32);
	}
}

void	init_vars(t_vars *vars)
{
	vars->collected = 0;
	vars->movement = 0;
	if (vars->map[0] == NULL)
	{
		write(1, "ERROR, no map\n", 14);
		final_cleaner(vars, 0);
		exit (1);
	}
	vars->win_w = ft_strlen(vars->map[0]);
	vars->win_h = get_height(vars->map);
	vars->left = 0;
}

int	check_file(char *argv)
{
	int	len;

	len = ft_strlen(argv);
	if (len >= 4 && ft_strcmp(&argv[len - 4], ".ber") == 0)
		return (0);
	write(1, "ERROR: map file not ending with .ber!\n", 38);
	exit (1);
}

int	main(int argc, char **argv)
{
	t_vars vars;

	if (argc != 2)
	{
		write(1, "ERROR: invalid number of arguments!\n", 36);
		exit(1);
	}
	check_file(argv[1]);
	vars.map = get_map(argv[1], &vars);
//	do stuff
	if (vars.map != NULL)
	{
		init_vars(&vars);
		check_map(&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window (vars.mlx,
				vars.win_w * 32, vars.win_h * 32, "So-Long");
		render_map(&vars, argv);
		mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
		mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
		mlx_loop(vars.mlx);
	}
	return (final_cleaner (&vars, 1), 0);
	//return (0);
}
