/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaburale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:49:57 by kaburale          #+#    #+#             */
/*   Updated: 2023/06/19 17:50:13 by kaburale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include "mlx.h"
# include "error.h"
# include "libft.h"

# define WIDTH	1920
# define HEIGHT 1080

// # define FT_INT_MAX 2147483647
// # define FT_INT_MIN -2147483648

// typedef enum s_projection
// {
// 	ISO,
// 	PARA
// }						t_projection;

typedef struct s_point
{
	int					x;
	int					y;
	int					z;
	int					color;
}						t_point;

typedef struct s_node_z
{
	int					z;
	int					color;
	struct s_node_z		*next;
}						t_node_z;

typedef struct s_map
{
	int					width;
	int					height;
	int					*z_arr;
	int					*color_arr;
}						t_map;

typedef struct s_data
{
	t_map				*map;
	t_node_z			*stack;

}						t_data;

void	exit_error(char *str);
t_map	*map_init(t_map *map);
int		map_read_stack(t_node_z **stack, t_map *map, int fd);
void	free_split(char **ptr);
void	free_line(char **ptr);
int		ft_atoi_base(char *str, int base_num);
int		ft_isvalid(char *str, int base_num);
void	map_read_array(t_node_z **stack, t_map *map);

#endif
