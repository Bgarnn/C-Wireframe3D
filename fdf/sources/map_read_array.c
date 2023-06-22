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

static void	malloc_check(int *arr, t_map *map)
{
	if (!arr)
		exit_error_free(READ_ARRAY_ERROR, map);
}

static int	update_max(int pop, int max)
{
	if (pop > max)
		return (pop);
	return (max);
}

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
	malloc_check(map->z_arr, map);
	map->color_arr = (int *)malloczero(size);
	malloc_check(map->color_arr, map);
	i = (map->width * map->height) - 1;
	while (i >= 0)
	{
		pop_node = stack_pop(stack);
		if (pop_node)
		{
			map->z_arr[i] = pop_node->z;
			map->color_arr[i] = pop_node->color;
			map->z_max = update_max(pop_node->z, map->z_max);
		}
		else
			break ;
		i--;
		free(pop_node);
	}
}
