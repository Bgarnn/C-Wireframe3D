# include "fdf.h"

static int	absolute(int nb)
{
	if (nb < 0)
		return (-nb);
	return (nb);
}

static int	ft_ismin(int x, int y)
{
	if (x < y)
		return (1);
	else
		return (-1);
}

static void	point_init(t_point *d, t_point *u, t_point p1, t_point p2)
{
	u->x = ft_ismin(p1.x, p2.x);
	u->y = ft_ismin(p1.y, p2.y);
	d->x = absolute(p2.x - p1.x);
	d->y = absolute(p2.y - p1.y);
}

static void	draw_pixel(t_data *data, int x, int y, int color)
{
	int	i;

	if ((x >= 0 && x < WIDTH) && (y >= 0 && y < HEIGHT))
	{
		i = (x * data->img.bits_per_pixel / 8) + (y * data->img.size_line);
		data->mlx.img_data[i] = color;
		data->mlx.img_data[++i] = color >> 8;
		data->mlx.img_data[++i] = color >> 16;
	}
}

void	draw_line(t_point p1, t_point p2, t_data *data)
{
	t_point	distance;
	t_point	update;
	t_point	cur;
	int		diff[2];

	point_init(&distance, &update, p1, p2);
	diff[0] = distance.x - distance.y;
	cur = p1;
	while (cur.x != p2.x || cur.y != p2.y)
	{
		draw_pixel(data, cur.x, cur.y, get_color(cur, p1, p2, distance));
		diff[1] = diff[0] * 2;
		if (diff[1] > -distance.y)
		{
			diff[0] -= distance.y;
			cur.x += update.x;
		}
		if (diff[1] < distance.x)
		{
			diff[0] += distance.x;
			cur.y += update.y;
		}
	}
}