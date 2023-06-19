/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:59:28 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/25 15:59:30 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*back;

	if (*lst == 0)
	{
		*lst = new;
	}
	else
	{
		back = ft_lstlast(*lst);
		back->next = new;
	}
}
// add (new) node at the end of (lst)