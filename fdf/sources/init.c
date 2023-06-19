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