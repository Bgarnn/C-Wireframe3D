/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 11:26:18 by kburalek          #+#    #+#             */
/*   Updated: 2023/02/15 13:22:55 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	{
		return (1);
	}
	return (0);
}
/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char	str[] = "ABcD123";
	int	alp = 0, ft = 0, i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if(isalpha(str[i]) != 0)
			alp++;
		if(ft_isalpha(str[i]) != 0)
			ft++;
	}
	printf("isalpha = %d\n", alp);
	printf("ft_isalpha = %d", ft);

}*/
