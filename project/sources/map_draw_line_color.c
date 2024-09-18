#include "fdf.h"

static int	light_adjust(int start, int end, double percentage)
{
	int	result;

	result = (((1 - percentage) * start) + (percentage * end));
	return (result);
}

static double	percent(int start, int end, int curr)
{
	double	cur_point;
	double	distance;

	cur_point = curr - start;
	distance = end - start;
	if (distance == 0)
		return (0);
	else
		return (cur_point / distance);
}

int	get_color(t_point cur, t_point start, t_point end, t_point distance)
{
	int		r;
	int		g;
	int		b;
	double	percentage;

	if (cur.color == end.color)
		return (cur.color);
	if (distance.x > distance.y)
		percentage = percent(start.x, end.x, cur.x);
	else
		percentage = percent(start.y, end.y, cur.y);
	r = light_adjust((start.color >> 16) & 0xFF,
			(end.color >> 16) & 0xFF, percentage);
	g = light_adjust((start.color >> 8) & 0xFF,
			(end.color >> 8) & 0xFF, percentage);
	b = light_adjust(start.color & 0xFF,
			end.color & 0xFF, percentage);
	return ((r << 16) | (g << 8) | b);
}
