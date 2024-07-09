/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lopie13 <lopie13@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 16:33:00 by mmata-al          #+#    #+#             */
/*   Updated: 2024/07/09 20:07:29 by lopie13          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_imgs	*new_img(int w, int h, t_vars *mlx, t_vars *window)
{
	t_imgs	*image;

	image = (t_imgs *)malloc(sizeof(t_imgs));
	image->win = window;
	image->img = mlx_new_image(mlx, w, h);
	image->addr = mlx_get_data_addr(image->img, &(image->bites_per_pxl),
			&(image->line_len), &(image->endian));
	image->width = w;
	image->height = h;
	//ft_printf("\n\nw=%d\n h=%d\n wid=%d\n hei=%d\n\n", w, h, image->width, image->height);
	return (image);
}

t_imgs	*new_file_img(char *path, void *mlx, void *window)
{
	t_imgs	*image;

	image = (t_imgs *)malloc(sizeof(t_imgs));
	//ft_printf("W: %d - H: %d\n", image->width, image->height);
	image->win = window;
	image->img = mlx_xpm_file_to_image(mlx, path, &image->width,
			&image->height);
	if (!image->img)
		write(2, "File could not be read\n", 23);
	else
		image->addr = mlx_get_data_addr(image->img, &(image->bites_per_pxl),
				&(image->line_len), &(image->endian));
	return (image);
}

void	put_pixel_img(t_imgs *img, int x, int y, int color)
{
	char	*dst;

	if (color == (int)0x00FFFFFF || color == -16777216)
		return ;
	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		dst = img->addr + (y * img->line_len + x * (img->bites_per_pxl / 8));
		*(unsigned int *)dst = color;
	}
}

unsigned int	get_pixel_img(t_imgs *img, int x, int y)
{
	return (*(unsigned int *)((img->addr + (y * img->line_len) + (x
				* img->bites_per_pxl / 8))));
}

void	put_img_to_img(t_imgs *dst, t_imgs *src, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	//ft_printf("1\n");
	//ft_printf("%d\n", src->width);
	while (i < src->width)
	{
		j = 0;
		while (j < src->height)
		{
			put_pixel_img(dst, x + i, y + j, get_pixel_img(src, i, j));
			j++;
		}
		i++;
	}
}
