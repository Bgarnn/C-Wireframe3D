/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 13:35:14 by kburalek          #+#    #+#             */
/*   Updated: 2023/02/15 13:49:43 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int c)
{
	if ((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z')
		|| (c >= 'a' && c <= 'z'))
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
	char	str[] = "ABc++D123--";
	int	alnum = 0, ft = 0, i = 0;

	for (i = 0; str[i] != '\0'; i++)
	{
		if(isalnum(str[i]) != 0)
			alnum++;
		if(ft_isalnum(str[i]) != 0)
			ft++;
	}
	printf("isalnum = %d\n", alnum);
	printf("ft_isalnum = %d", ft);

}*/
