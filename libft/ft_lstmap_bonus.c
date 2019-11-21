/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marandre <marandre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:13:51 by marandre          #+#    #+#             */
/*   Updated: 2019/10/16 17:47:36 by marandre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(void*))
{
	t_list	*list;

	if (lst == NULL || !f)
		return (NULL);
	if (!(list = ft_lstnew(lst->content)))
		return (NULL);
	list->next = f(ft_lstmap(lst->next, f));
	return (list);
}
