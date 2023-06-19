/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 14:25:13 by kburalek          #+#    #+#             */
/*   Updated: 2023/02/15 14:25:15 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (c - 32);
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
		printf("%c", toupper(str[i]));
	}
    printf("\n");
    for (i = 0; str[i] != '\0'; i++)
	{
        printf("%c", ft_toupper(str[i]));
	}
}*/
