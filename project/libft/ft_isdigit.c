/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:23:27 by kburalek          #+#    #+#             */
/*   Updated: 2023/02/15 13:34:11 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	int	dg = 0, ft = 0, i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if(isdigit(str[i]) != 0)
			dg++;
		if(ft_isdigit(str[i]) != 0)
			ft++;
	}
	printf("isdigit = %d\n", dg);
	printf("ft_isdigit = %d", ft);
}*/
