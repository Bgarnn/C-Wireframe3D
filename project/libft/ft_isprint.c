/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:13:19 by kburalek          #+#    #+#             */
/*   Updated: 2023/02/15 14:13:44 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
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
	char	str[] = "ABcD123?s";
	int	pr = 0, ft = 0, i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if(isprint(str[i]) != 0)
			pr++;
		if(ft_isprint(str[i]) != 0)
			ft++;
	}
	printf("isprint = %d\n", pr);
	printf("ft_isprint = %d", ft);
}*/
