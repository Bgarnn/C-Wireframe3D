#include "fdf.h"

static t_node_z	*stack_new(char *str)
{
	t_node_z	*new;
	char		**tmp_z;

	new = (t_node_z *)malloczero(sizeof(t_node_z));
	if (!new)
		exit_error(NEW_STACK_ERROR);
	tmp_z = ft_split(str, ',');
	if ((!tmp_z) || (!ft_isvalid(tmp_z[0], 10)) || (tmp_z[1] && !ft_isvalid(tmp_z[1], 16)))
		exit_error(NEW_STACK_ERROR);
	new->z = ft_atoi(tmp_z[0]);
	if (tmp_z[1] != NULL )
		new->color = ft_atoi_base(tmp_z[1], 16);
	else
		new->color = -1;
	new->next = NULL;
	free_split(tmp_z);
	return (new);
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
		stack_add(stack, stack_new(*(line_split)));
		tmp_width++;
		line_split++;
	}
	if (map->height == 0)
		map->width = tmp_width;
	else if (map->width != tmp_width)
		exit_error(SIZE_ERROR);
}

int	map_read_stack(t_node_z **stack, t_map *map, int fd)
{
	char	*line;
	char	**line_split;

	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break;
		line_split = ft_split(line, ' ');
		if (!line_split)
			exit_error(LINE_SPLIT_ERROR);
		line_to_stack(line_split, stack, map);
		free_split(line_split);
		free_line(&line);
		map->height++;
	}
	if (!(*stack))
		exit_error(READ_STACK_ERROR);
	return (0);
}

