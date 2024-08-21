#include "so_long.h"

void	collected(t_vars *v)
{
	v->collected--;
	v->map[(v->y_p / 32)][(v->x_p / 32)] = '0';
	if (v->collected == 0)
		mlx_put_image_to_window(v->mlx, v->win, v->assets->gwd->img,
			v->e_x, v->e_y);
}

void	move_left(t_vars *v)
{
	mlx_put_image_to_window(
		v->mlx, v->win, v->assets->ground->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32)][(v->x_p / 32) - 1] == 'E')
		exit_verifier(v, 0, 0);
	else if (v->map[(v->y_p / 32)][(v->x_p / 32) - 1] != '1')
	{
		v->x_p -= 32;
		put_text(v);
	}
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'C')
		collected(v);
	v->left = 1;
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->gwcl->img,
		v->x_p, v->y_p);
}

void	move_right(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->ground->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32)][(v->x_p / 32) + 1] == 'E')
		exit_verifier(v, 0, 1);
	else if (v->map[(v->y_p / 32)][(v->x_p / 32) + 1] != '1')
	{
		v->x_p += 32;
		put_text(v);
	}
	if (v->map[(v->y_p / 32)][(v->x_p / 32)] == 'C')
		collected(v);
	v->left = 0;
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->gwcr->img,
		v->x_p, v->y_p);
}

void	move_up(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->ground->img, v->x_p, v->y_p);
	if ((v)->map[((v)->y_p / 32) - 1][((v)->x_p / 32)] == 'E')
		exit_verifier(v, 1, 0);
	else if ((v)->map[((v)->y_p / 32) - 1][((v)->x_p / 32)] != '1')
	{
		if (v->map[(v->y_p / 32) - 1][(v->x_p / 32)] == 'C')
		{
			v->map[(v->y_p / 32) - 1][(v->x_p / 32)] = 'P';
			collected(v);
		}
		(v)->y_p -= 32;
		put_text(v);
	}
	move_idkup(v);
}

void	move_down(t_vars *v)
{
	mlx_put_image_to_window(v->mlx, v->win,
		v->assets->ground->img, v->x_p, v->y_p);
	if (v->map[(v->y_p / 32) + 1][(v->x_p / 32)] == 'E')
		exit_verifier(v, 1, 1);
	else if (v->map[(v->y_p / 32) + 1][(v->x_p / 32)] != '1')
	{
		if (v->map[(v->y_p / 32) + 1][(v->x_p / 32)] == 'C')
		{
			v->map[(v->y_p / 32) + 1][(v->x_p / 32)] = 'P';
			collected(v);
		}	
		v->y_p += 32;
		put_text(v);
	}
	move_idk(v);
}

//need to "create" exit_verifier and put_text