/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:32:53 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 15:32:54 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
// allocate new string, S1 + s2