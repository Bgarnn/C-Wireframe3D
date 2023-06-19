/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 16:01:13 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/25 16:01:16 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*currentnode;
	t_list	*run;

	if (lst == 0 || del == 0)
		return ;
	else if (lst != 0)
	{
		run = *lst;
		while (run != 0)
		{
			currentnode = run;
			run = run->next;
			del(currentnode->content);
			free(currentnode);
		}
	*lst = NULL;
	}
}
// delete and free all in (lst)