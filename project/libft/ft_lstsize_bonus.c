/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 15:58:04 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/25 15:58:06 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*run;
	int		i;

	i = 0;
	run = lst;
	while (run != 0)
	{
		run = run->next;
		i++;
	}
	return (i);
}
// count node in (lst)