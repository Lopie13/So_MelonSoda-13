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
	mlx_destroy_image(v->mlx, v->assets->door->img);
	free(v->assets->door);
	mlx_destroy_image(v->mlx, v->assets->coin->img);
	free(v->assets->coin);
	mlx_destroy_image(v->mlx, v->assets->gwd->img);
	free(v->assets->gwd);
	mlx_destroy_image(v->mlx, v->assets->gwcoll->img);
	free(v->assets->gwcoll);
	assets_cleaner2(v);
}

void	assets_initiator2(t_vars *v)
{
	v->assets->wall = new_file_img("assets/temp/wall.xpm", v->mlx, v->win);
	v->assets->coin = new_file_img("assets/temp/coin.xpm", v->mlx, v->win);
	v->assets->gwcoll = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwcoll, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwcoll, v->assets->coin, 0, 0);
	v->assets->gwcu = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwcu, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwcu, v->assets->charaup, 0, 0);
}

void	assets_initiator(t_vars *v)
{
	v->assets->chara = new_file_img("assets/temp/character.xpm", v->mlx, v->win);
	v->assets->ground = new_file_img("assets/temp/ground.xpm", v->mlx, v->win);
	v->assets->door = new_file_img("assets/temp/closeddoor.xpm", v->mlx, v->win);
	v->assets->gwc = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwc, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwc, v->assets->chara, 0, 0);
	v->assets->gwd = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwd, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwd, v->assets->door, 0, 0);
	v->assets->charaleft = new_file_img("assets/temp/walk-left.xpm", v->mlx, v->win);
	v->assets->chararight = new_file_img("assets/temp/walk-right.xpm", v->mlx, v->win);
	v->assets->charaup = new_file_img("assets/temp/walk-up.xpm", v->mlx, v->win);
	v->assets->gwcl = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwcl, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwcl, v->assets->charaleft, 0, 0);
	v->assets->gwcr = new_img(32, 32, v->mlx, v->win);
	put_img_to_img(v->assets->gwcr, v->assets->ground, 0, 0);
	put_img_to_img(v->assets->gwcr, v->assets->chararight, 0, 0);
	assets_initiator2(v);
}

void	put_image_to_map(char p, int x1, int y1, t_vars *v)
{
	//ft_printf("%c\n", v->map[0][0]);
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
