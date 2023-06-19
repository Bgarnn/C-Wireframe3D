/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:01:50 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/25 16:01:51 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst != 0 && f != 0)
	{
		while (lst != 0)
		{
			f(lst->content);
			lst = lst->next;
		}
	}
}
// apply fx(f) each node