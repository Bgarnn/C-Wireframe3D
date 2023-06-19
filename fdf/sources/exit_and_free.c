#include "fdf.h"
#include "libft.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>


void	exit_error(char *str)
{
	if (errno == 0)
		ft_putendl_fd(str, 2);
	else
		perror(str);
	exit(1);
}

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

void	free_line(char **ptr)
{
	if (ptr != NULL && *ptr != NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}