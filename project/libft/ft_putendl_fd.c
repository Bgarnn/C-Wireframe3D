/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kburalek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 15:37:25 by kburalek          #+#    #+#             */
/*   Updated: 2023/04/21 15:37:27 by kburalek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putendl_fd(char *str, int fd)
{
	if (str == NULL || fd < 0)
		return ;
	write(fd, str, ft_strlen(str));
	write(fd, "\n", 1);
}
// output (str) to the given (fd), followed by newline