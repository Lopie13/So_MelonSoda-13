/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/15 18:28:00 by mmata-al          #+#    #+#             */
/*   Updated: 2024/05/15 18:28:01 by mmata-al         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include "../libs/minilibx-linux/mlx.h"
//# include "../libs/get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
//# include <X11/keysym.h>
//# include "../libs/libft/libft.h"

typedef struct s_imgs
{
	char		*addr;
	int			bites_per_pxl;
	int			endian; //<---THIS
	int			height;
	int			line_len;
	int			width;
	void		*win;
	void		*img;
}				t_imgs;

typedef struct s_assets
{
	//t_imgs	*asset;

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

#endif
