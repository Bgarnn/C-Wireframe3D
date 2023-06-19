/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/01 13:57:47 by kburalek          #+#    #+#             */
/*   Updated: 2023/05/01 13:57:50 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

char	*ft_strdup(const char *str)
{
	char	*ptr;
	size_t	i;

	i = 0;
	ptr = (char *)malloc((ft_strlen(str) + 1) * sizeof(char));
	if (ptr == NULL)
		return (NULL);
	if (ptr != NULL)
	{
		while (str[i] != '\0')
		{
			ptr[i] = str[i];
			i++;
		}
		ptr[i] = '\0';
	}
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		s1_i;
	int		s2_i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_i = 0;
	s2_i = 0;
	str = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	while (s1[s1_i] != '\0')
	{
		str[s1_i] = s1[s1_i];
		s1_i++;
	}
	while (s2[s2_i] != '\0')
	{
		str[s1_i + s2_i] = s2[s2_i];
		s2_i++;
	}
	str[s1_i + s2_i] = '\0';
	return (str);
}

char	*ft_strchr(const char *str, int val)
{
	char	*ptr;

	ptr = (char *)str;
	while (*ptr != '\0')
	{
		if (*ptr == (char)val)
			return (ptr);
		ptr++;
	}
	if (val == '\0')
		return (ptr);
	return (NULL);
}

char	*ft_substr(char const *str, unsigned int start, size_t num)
{
	char	*sub;
	size_t	str_len;
	size_t	i;

	i = 0;
	if (str == NULL)
		return (NULL);
	str_len = ft_strlen(str);
	if (start >= str_len)
		return (ft_strdup(""));
	if (num > (str_len - start))
		num = str_len - start;
	sub = (char *)malloc(sizeof(char) * (num + 1));
	if (sub == NULL)
		return (NULL);
	while (i < num)
	{
		sub[i] = str[start];
		i++;
		start++;
	}
	sub[num] = '\0';
	return (sub);
}
