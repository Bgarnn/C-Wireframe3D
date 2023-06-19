/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read_array.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaburale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:26:11 by kaburale          #+#    #+#             */
/*   Updated: 2023/06/19 17:26:14 by kaburale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static t_node_z	*stack_pop(t_node_z **stack)
{
	t_node_z	*pop_node;

	pop_node = NULL;
	if (stack && *stack)
	{
		pop_node = *stack;
		*stack = (*stack)->next;
	}
	return (pop_node);
}

void	map_read_array(t_node_z **stack, t_map *map)
{
	size_t		i;
	size_t		size;
	t_node_z	*pop_node;

	size = (map->width * map->height) * sizeof(int);
	map->z_arr = (int *)malloczero(size);
	if (!(map->z_arr))
		exit_error(READ_ARRAY_ERROR);
	map->color_arr = (int *)malloczero(size);
	if (!(map->color_arr))
		exit_error(READ_ARRAY_ERROR);
	i = (map->width * map->height) - 1;
	while (i >= 0)
	{
		pop_node = stack_pop(stack);
		if (pop_node)
		{
			map->z_arr[i] = pop_node->z;
			map->color_arr[i] = pop_node->color;
		}
		else
			break ;
		i--;
		free(pop_node);
	}
}
