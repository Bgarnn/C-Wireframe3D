/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaburale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:27:57 by kaburale          #+#    #+#             */
/*   Updated: 2023/06/19 17:27:59 by kaburale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	free_split(char **ptr)
{
	size_t	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static void	free_line(char **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

static void	stack_add(t_node_z **stack, t_node_z *new)
{
	if (stack)
	{
		if (new)
			new->next = *stack;
		*stack = new;
	}
}

static void	line_to_stack(char **line_split, t_node_z **stack, t_map *map)
{
	int	tmp_width;

	tmp_width = 0;
	while (*line_split)
	{
		stack_add(stack, (stack_new(*(line_split), map)));
		tmp_width++;
		line_split++;
	}
	if (map->height == 0)
		map->width = tmp_width;
	else if (map->width != tmp_width)
		exit_error_free(SIZE_ERROR, map);
}

int	map_read_stack(t_node_z **stack, t_map *map, int fd)
{
	char	*line;
	char	**line_split;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		line_split = ft_split(line, ' ');
		if (!line_split)
			exit_error_free(LINE_SPLIT_ERROR, map);
		line_to_stack(line_split, stack, map);
		free_split(line_split);
		free_line(&line);
		map->height++;
	}
	stack = NULL;
	if (!(*stack))
		exit_error_free(READ_STACK_ERROR, map);
	return (0);
}
