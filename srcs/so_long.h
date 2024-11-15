/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopie13 <lopie13@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:28:00 by mmata-al          #+#    #+#             */
/*   Updated: 2024/09/19 12:16:30 by lopie13          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libs/minilibx-linux/mlx.h"
# include "./gnl/get_next_line_bonus.h"
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
	t_imgs		*charaup;
	t_imgs		*charaleft;
	t_imgs		*chararight;
	t_imgs		*ground;
	t_imgs		*wall;
	t_imgs		*door;
	t_imgs		*coin;
	t_imgs		*gwc;
	t_imgs		*gwcl;
	t_imgs		*gwcr;
	t_imgs		*gwcu;
	t_imgs		*gwd;
	t_imgs		*gwcoll;

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
	int				collected;
	int				left;
	t_assets		*assets;
}	t_vars;

typedef struct s_map
{
	int	c;
	int	p;
	int	e;
	int	x;
	int	y;
}	t_map;

// functions
char	*ft_join_strings(char *s1, char *s2);
char	**get_map(char *fullmap, t_vars *vars);
void	ft_message_error(t_vars *vars, int assets);
int		get_height(char **map);
int		map_xloop(t_vars *vars, int x1, int y1, int map_y);
int		ft_exit(t_vars *vars);
void	put_image_to_map(char p, int x1, int y1, t_vars *v);
void	flood_checker(t_vars *vars, char **argv);
void	flood_fill(char **map, int x, int y);
void	check_elements(t_vars *vars);
t_map	map_ext(t_vars *vars, t_map map);
void	assets_cleaner(t_vars *v);
void	final_cleaner(t_vars *vars, int assets);
void	check_map(t_vars *vars);
t_imgs	*new_img(int w, int h, t_vars *mlx, t_vars *window);
t_imgs	*new_file_img(char *path, void *mlx, void *window);
void	put_img_to_img(t_imgs *dst, t_imgs *src, int x, int y);
char	*error_message(t_map *map);
int		check_c(t_vars *vars);
int		check_e(t_vars *vars);
void	ft_error(t_vars *vars, char *message);
int		ft_exit(t_vars *vars);
int		ft_strcmp(char *s1, char *s2);
void	assets_initiator(t_vars *v);
void	invisible_door(t_vars *v, int x1, int y1);
void	get_player(t_vars *vars);
void	init_vars(t_vars *vars);
void	put_text(t_vars *v);
void	exit_verifier(t_vars *v, int xy, int vet);
void	exit_door(t_vars *v);
void	move_left(t_vars *v);
void	move_right(t_vars *v);
void	move_up(t_vars *v);
void	move_down(t_vars *v);
int		key_hook(int keycode, t_vars *vars);
void	move_idk(t_vars *v);
void	collected(t_vars *v);
void	ft_file_error(char *file);
void	move_idkup(t_vars *v);
int	freemaplined(char *str);

#endif
