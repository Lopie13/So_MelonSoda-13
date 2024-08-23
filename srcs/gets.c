/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopie13 <lopie13@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:40:32 by mmata-al          #+#    #+#             */
/*   Updated: 2024/08/23 18:33:43 by lopie13          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*liner(int fd, char *line, char *ml)
{
	char	*temp;

	while (line)
	{
		line = get_next_line(fd);
		if (line == NULL || line[0] == '\n')
		{
			free(line);
			break ;
		}
		temp = ft_join_strings(ml, line);
		free(ml);
		ml = temp;
		free(line);
	}
	return (ml);
}

int	get_height(char **map)
{
	int	i;

	i = 0;
	while (map[i] != NULL)
		i++;
	return (i);
}

char	**get_map(char *mapfile, t_vars *vars)
{
	char	**splited;
	char	*line;
	char	*maplined;
	int		fd;

	line = "";
	maplined = ft_strdup("");
	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
	{
		free(maplined);
		ft_file_error(mapfile);
	}
	maplined = liner(fd, line, maplined);
	close(fd);
	if (!maplined)
		ft_message_error(vars, 0);
	splited = ft_split(maplined, '\n');
	free(maplined);
	return (splited);
}

void	get_player(t_vars *vars)
{
	int	map_y;
	int	backup_w;
	int	map_x;

	map_y = 0;
	backup_w = vars->win_w;
	while (vars->win_h > 0)
	{
		map_x = 0;
		while (vars->win_w > 0)
		{
			if (vars->map[map_y][map_x] == 'P')
			{
				vars->x_p = map_x;
				vars->y_p = map_y;
			}
			vars->win_w--;
			map_x++;
		}
		vars->win_w = backup_w;
		map_y++;
		vars->win_h--;
	}
	init_vars(vars);
}
