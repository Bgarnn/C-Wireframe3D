/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:53:58 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 14:40:40 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	char	*ptrs;
	char	*ptrd;

	ptrs = (char *)src;
	ptrd = (char *)dst;
	if (dst > src)
	{
		while (num > 0)
		{
			num--;
			ptrd[num] = ptrs[num];
		}
		return (dst);
	}
	else
		return (ft_memcpy(dst, src, num));
}
// copy from (src) to (dst), (num) byte, can overlap