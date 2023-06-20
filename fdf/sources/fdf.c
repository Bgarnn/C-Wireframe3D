/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaburale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 16:37:09 by kaburale          #+#    #+#             */
/*   Updated: 2023/06/19 16:37:12 by kaburale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

	// char	*all_line;

	// all_line = "";
	// while(all_line != NULL)
	// { 
	// 	all_line = get_next_line(fd);
	// 	printf("%s$\n", all_line);
	// }
	// char	*line;
	// char	**line_split;
	// line = get_next_line(fd);
	// line_split = ft_split(line, ' ');
	// printf("%s$\n%s", line, line_split);		
	// printf("w =%d, h =%d", data.map->width, data.map->height);
