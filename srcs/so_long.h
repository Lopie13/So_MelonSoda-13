/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:28:00 by mmata-al          #+#    #+#             */
/*   Updated: 2024/06/04 19:23:19 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libs/minilibx-linux/mlx.h"
# include "../libs/gnl/get_next_line_bonus.h"
# include <fcntl.h>
# include <stdio.h>
# include <X11/keysym.h>
# include "../libs/libft+/libft.h"

typedef struct s_imgs
{
	char		*addr;
	int			bites_per_pxl;
	int			endian;
	int			height;
	int			line_len;
	int			width;
	void		*win;
	void		*img;
}				t_imgs;

typedef struct s_assets
{
	//t_imgs	*asset;
	t_imgs		*chara;
	t_imgs		*ground;
	t_imgs		*wall;
	t_imgs		*gwc;

}	t_assets;

typedef struct s_vars
{
	void			*mlx;
	void			*img;
	void			*win;
	int				win_w;
	int				win_h;
	int				x_p;
	int				y_p;
	int				e_x;
	int				e_y;
	int				movement;
	char			**map;
	//int				collect;
	//int				lantern;
	//int				there_was_lantern;
	//int				left;
	t_assets		*assets;
}	t_vars;

typedef struct s_map
{
	int	c;
	int	p;
	int	e;
	int	l;
	int	x;
	int	y;
}	t_map;

// functions
char	*ft_join_strings(char *s1, char *s2);
char	**get_map(char *fullmap, t_vars *vars);
void	ft_message_error(t_vars *vars, int assets);
int	get_height(char **map);
int	map_xloop(t_vars *vars, int x1, int y1, int map_y);
int	ft_exit(t_vars *vars);
void	put_image_to_map(char p, int x1, int y1, t_vars *v);
void	flood_checker(t_vars *vars, char **argv);
void	flood_fill(char **map, int x, int y);
void	check_elements(t_vars *vars);
t_map	map_ext(t_vars *vars, t_map map);
void	assets_cleaner(t_vars *v);
void	final_cleaner(t_vars *vars, int assets);

#endif
