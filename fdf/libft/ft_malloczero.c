/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloczero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kaburale <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 17:46:57 by kaburale          #+#    #+#             */
/*   Updated: 2023/06/19 17:46:59 by kaburale         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*malloczero(size_t size)
{
	void	*dst;

	dst = malloc(size);
	if (dst)
		ft_bzero(dst, size);
	return (dst);
}
