/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:42:45 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 14:42:47 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int val, size_t num)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (num > 0)
	{
		if (*ptr == (unsigned char)val)
			return (ptr);
		ptr++;
		num--;
	}
	return (NULL);
}
// locate (val) in (str), within (num) byte