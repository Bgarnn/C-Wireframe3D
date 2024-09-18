/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:30:43 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 15:30:46 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	src_i;
	size_t	dst_i;

	src_i = 0;
	dst_i = 0;
	if (dstsize == 0 && dst == NULL)
		return (ft_strlen(src));
	if (ft_strlen(dst) >= dstsize)
		return (ft_strlen(src) + dstsize);
	while ((dst_i < dstsize - 1) && (dst[dst_i] != '\0'))
		dst_i++;
	while ((dst_i + src_i < dstsize - 1) && (src[src_i] != '\0'))
	{
		dst[dst_i + src_i] = src[src_i];
		src_i++;
	}
	dst[dst_i + src_i] = '\0';
	return (ft_strlen(src) + dst_i);
}
// append (src) to end of (dst), cannot overlap, NULL-terminate
// return length of (src) + initial length of (dst)