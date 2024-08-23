#include "so_long.h"

void	exit_verifier(t_vars *v, int xy, int vet)
{
	if (v->collected <= 0)
		exit_door(v);
	else
	{
		if (xy == 0)
		{
			if (vet == 0)
				v->x_p -= 32;
			else if (vet == 1)
				v->x_p += 32;
		}
		else if (xy == 1)
		{
			if (vet == 0)
				v->y_p -= 32;
			else if (vet == 1)
				v->y_p += 32;
		}
	}
}

void	put_text(t_vars *v)
{
	int		img_w;
	int		img_h;
	char	*text;
	char	*number;

	number = ft_itoa(++(v)->movement);
	text = ft_join_strings("Move: ", number);
	v->img = mlx_xpm_file_to_image(
			v->mlx, "./img/wall.xpm", &img_w, &img_h);
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets->wall->img, 0, 0);
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets->wall->img, 32, 0);
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets->wall->img, 32 * 2, 0);
	mlx_string_put(v->mlx, v->win, 5, 10, 0xfffffff, text);
	ft_printf("%s\n", number);
	free(text);
	free(number);
}

void	move_idk(t_vars *v)
{
	if (v->left == 1)
	{
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwc->img, v->x_p, v->y_p);
	}
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwc->img,
			v->x_p, v->y_p);
}

void	move_idkup(t_vars *v)
{
	if (v->left == 1)
	{
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwcu->img, v->x_p, v->y_p);
	}
	else
		mlx_put_image_to_window(v->mlx, v->win,
			v->assets->gwcu->img,
			v->x_p, v->y_p);
}

void	invisible_door(t_vars *v, int x1, int y1)
{
	mlx_put_image_to_window(v->mlx, v->win, v->assets->ground->img, x1, y1);
	v->e_x = x1;
	v->e_y = y1;
}
