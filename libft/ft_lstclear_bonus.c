/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:16:08 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 17:36:20 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list *temp;
	t_list *next;

	if (!lst)
		return ;
	next = *lst;
	while (next && del)
	{
		temp = next;
		next = temp->next;
		del(temp->content);
		free(temp);
	}
	*lst = 0;
}
