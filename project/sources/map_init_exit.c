#include "fdf.h"

t_map	*map_init(t_map *map)
{
	map = (t_map *)malloczero(sizeof(t_map));
	if (!(map))
		exit_error(MAP_INIT_ERROR);
	map->width = 0;
	map->height = 0;
	map->z_arr = NULL;
	map->color_arr = NULL;
	return (map);
}

void	exit_error(char *str)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(1);
}

void	exit_error_free(char *str, t_map *map)
{
	if (map)
	{
		if (map->z_arr)
			free(map->z_arr);
		if (map->color_arr)
			free(map->color_arr);
		free(map);
	}
	exit_error(str);
}

void	exit_error_free_2(char *str, t_map *map, t_node_z *ptr)
{
	if (ptr)
		free(ptr);
	exit_error_free(str, map);
}

void	free_ptr(t_map *map)
{
	if (map)
	{
		if (map->z_arr)
			free(map->z_arr);
		if (map->color_arr)
			free(map->color_arr);
		free(map);
	}
}
