/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:33:15 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 15:33:16 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	start;
	size_t	end;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while ((s1[start] != '\0') && (ft_strchr(set, s1[start])))
		start++;
	while ((s1[end - 1] != '\0') && (end > start)
		&& (ft_strchr(set, s1[end - 1])))
		end--;
	str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 1);
	return (str);
}
// trim (set) of character from string (s), both front & back