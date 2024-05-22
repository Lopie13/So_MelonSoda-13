/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:28:28 by mmata-al          #+#    #+#             */
/*   Updated: 2024/05/15 19:21:32 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file(char *argv)
{
	int	len;

	len = 0;
	while (argv[len])
		len++;
	while (len)
	{
		if (argv[len] == 'r')
			if (argv[len - 1] == 'e')
				if (argv[len - 2] == 'b')
					if (argv[len - 3] == '.')
						return (0);
		len--;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_vars vars;

	if (argc != 2)
	{
		write(1, "ERROR\n", 6);
		exit(1);
	}
	check_file(argv[1]);
//	vars.map = get_map(agrv[1], &vars)
//	do stuff
	return (0);
}

	/*check_file_is_valid(argv[1]);
	vars.map = get_map(argv[1], &vars);
	if (vars.map != NULL)
	{
		init_vars(&vars);
		check_map_valid(&vars);
		vars.mlx = mlx_init();
		vars.win = mlx_new_window (vars.mlx,
				vars.win_w * 32, vars.win_h * 32, "So-Long");
		render_map(&vars, argv);
		mlx_string_put(vars.mlx, vars.win, 5, 10, 0xffffff, "Move: 0");
		mlx_hook(vars.win, 2, (1L << 0), key_hook, &vars);
		mlx_hook(vars.win, 17, (1L << 0), ft_exit, &vars);
		mlx_loop(vars.mlx);
	}
	return (final_cleaner (&vars, 1), 0);*/