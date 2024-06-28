#include "so_long.h"

void	assets_cleaner2(t_vars *v)
{
	mlx_destroy_image(v->mlx, v->assets->gwc->img);
	free(v->assets->gwc);
	mlx_destroy_image(v->mlx, v->assets->wall->img);
	free(v->assets->wall);
	free(v->assets);
}

void	assets_cleaner(t_vars *v)
{
	mlx_destroy_image(v->mlx, v->assets->chara->img);
	free(v->assets->chara);
	mlx_destroy_image(v->mlx, v->assets->ground->img);
	free(v->assets->ground);
	/* mlx_destroy_image(v->mlx, v->assets->gwc2->img);
	free(v->assets->gwc2); */
	mlx_destroy_image(v->mlx, v->assets->gwc->img);
	free(v->assets->gwc);
	assets_cleaner2(v);
}

void	assets_initiator2(t_vars *v)
{
	v->assets->gwc = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwc, v->assets->ground, 0, 0);
	v->assets->wall = new_file_img("../assets/temp/wall.xpm", v->mlx, v->win);
}

void	assets_initiator(t_vars *v)
{
	v->assets->chara = new_file_img("../assets/temp/character.xpm", v->mlx, v->win);
	v->assets->ground = new_file_img("../assets/temp/ground.xpm", v->mlx, v->win);
	v->assets->gwc = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwc, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwc, v->assets->chara, 0, 0);
	assets_initiator2(v);
}

void	put_image_to_map(char p, int x1, int y1, t_vars *v)
{
	if (p == '1')
		mlx_put_image_to_window(v->mlx, v->win, v->assets->wall->img, x1, y1);
	else if (p == 'C')
	{
		mlx_put_image_to_window(v->mlx, v->win, v->assets->gwcoll->img, x1, y1);
		v->collected++;
	}
	else if (p == 'E')
		invisible_door(v, x1, y1);
	else if (p == 'P')
	{
		v->y_p = y1;
		v->x_p = x1;
		mlx_put_image_to_window(v->mlx, v->win, v->assets->gwc->img, x1, y1);
	}
	else
		mlx_put_image_to_window(v->mlx, v->win, v->assets->ground->img, x1, y1);
}
