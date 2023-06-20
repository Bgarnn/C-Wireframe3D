# include "fdf.h"

static void	convert_iso(int *x, int *y, int z)
{
	int	old_x;
	int	old_y;

	old_x = *x;
	old_y = *y;
	*x = (old_x - old_y) * cos(0.523599);
	*y = -z + (old_x + old_y) * sin(0.523599);
}

static t_point	plot_xyz(t_point point, t_data *data)
{
	point.x *= data->map->scale;
	point.y *= data->map->scale;
	point.z *= data->map->scale / 2;
	point.x -= (data->map->width * data->map->scale) / 2;
	point.y -= (data->map->height * data->map->scale) / 2;
	convert_iso(&point.x, &point.y, point.z);
	point.x += WIDTH / 2;
	point.y += (HEIGHT) / 2;
	return (point);
}

static t_point	get_point(int x, int y, t_map *map)
{
	t_point		point;
	size_t		i;

	i = (y * map->width) + x;
	point.x = x;
	point.y = y;
	point.z = map->z_arr[i];
	if (map->color_arr[i] == -1)
		point.color = LINE_COLOR;
	else
		point.color = map->color_arr[i];
	return (point);
}

static void	get_background(t_data *data)
{
	int		*bg_color;
	size_t	i;

	ft_bzero(data->mlx.img_data, (WIDTH * HEIGHT) * (data->img.bits_per_pixel / 8));
	bg_color = (int *)(data->mlx.img_data);
	i = 0;
	while (i < (WIDTH * HEIGHT))
	{
		bg_color[i] = BG_COLOR;
		i++;
	}
}


void	map_draw (t_map *map, t_data *data)
{
	int	x;
	int	y;

	get_background(data);
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (x != map->width - 1)
				draw_line(plot_xyz(get_point(x, y, map), data),
					plot_xyz(get_point(x + 1, y, map), data), data);
			if (y != map->height - 1)
				draw_line(plot_xyz(get_point(x, y, map), data),
					plot_xyz(get_point(x, y + 1, map), data), data);
			x++;
		}
		y++;
	}

}
