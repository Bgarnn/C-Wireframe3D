#include "libft.h"

void	*malloczero(size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (dst)
		ft_bzero(dst, size);
	return (dst);
}