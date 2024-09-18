/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:31:16 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 15:31:18 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *val, size_t num)
{
	size_t	val_i;
	size_t	str_i;

	str_i = 0;
	val_i = 0;
	if (val[val_i] == '\0')
		return ((char *)str);
	while ((str_i < num) && (str[str_i] != '\0'))
	{
		if (str[str_i] == val[val_i])
		{
			while ((str[str_i + val_i] == val[val_i]) && (str_i + val_i < num))
			{
				if (val[val_i + 1] == '\0')
					return ((char *)str + str_i);
				val_i++;
			}
			val_i = 0;
		}
		str_i++;
	}
	return (NULL);
}
// search string (val) im string (str), search (num) character
// If (val) = empty str -> return (str), If no (val) --> return NULL
// If (val) exist -> pointer to the first occurance
