/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gets.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:40:32 by mmata-al          #+#    #+#             */
/*   Updated: 2024/06/04 18:32:33 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_message_error(t_vars *vars, int assets)
{
	write(1, "ERROR\n", 7);
	//final_cleaner(vars, assets);
	exit(1);
}

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

char	**get_map(char *fullmap, t_vars *vars)
{
        char	*line;
	char	*maplined;
	int		fd;

	line = "";
	maplined = ft_strdup("");
	fd = open(fullmap, O_RDONLY);
	if (fd < 0)
		ft_message_error(vars, 0);
	maplined = liner(fd, line, maplined);
	close(fd);
	if (!maplined)
		ft_message_error(vars, 0);
	return (ft_split(maplined, '\n'));
}
