#include "fdf.h"

int	main(int ac, char *av[])
{
	int				fd;
	t_data			data;

	errno = 0;
	data.stack = NULL;
	if (ac != 2)
		exit_error(INPUT_ERROR);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		exit_error(OPEN_ERROR);
	data.map = map_init(data.map);
	map_read_stack(&data.stack, data.map, fd);
	map_read_array(&data.stack, data.map);
	mlx_open(&data);
	return (0);
}
