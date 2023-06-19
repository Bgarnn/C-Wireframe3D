/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:47:53 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 14:47:55 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int val)
{
	char	*ptr;
	int		i;

	ptr = (char *)str;
	i = ft_strlen(str);
	if (val == '\0')
		return ((ptr) + i);
	while (i >= 0)
	{
		if (ptr[i] == (char)val)
			return ((ptr) + i);
		i--;
	}
	return (NULL);
}
// locate first (val) in (str), NULL-terminate