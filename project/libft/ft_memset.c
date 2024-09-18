/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 13:46:21 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 13:46:27 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int val, size_t num)
{
	unsigned char	*ptr;

	ptr = (unsigned char *)str;
	while (num > 0)
	{
		*ptr = (unsigned char)val;
		num--;
		ptr++;
	}
	return (str);
}
// fill (str) with (val), (num) byte