/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:05:20 by kburalek          #+#    #+#             */
/*   Updated: 2023/02/15 17:28:34 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (c + 32);
	}
	return (c);
}
/*
#include <ctype.h>
#include <stdio.h>
int main(void)
{
	char	str[] = "asdf**UJDHF";
	int	i;

	for (i = 0; str[i] != '\0'; i++)
	{
		printf("%c", tolower(str[i]));
	}
	printf("\n");
	for (i = 0; str[i] != '\0'; i++)
	{
		printf("%c", ft_tolower(str[i]));
	}
}*/
