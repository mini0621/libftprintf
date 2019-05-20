/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/08 14:24:08 by mnishimo          #+#    #+#             */
/*   Updated: 2019/05/20 10:37:37 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_list	*ft_lstdup(t_list *src, void (*cp)(t_list *, t_list *))
{
	t_list	*cur;
	t_list	*ret;
	t_list	*last;
	t_list	*nl;

	cur = src;
	ret = NULL;
	last = NULL;
	while (cur)
	{
		if (!(nl = ft_lstnew(NULL, cur->content_size)))
			return (ret);
		cp(nl, cur);
		if (!ret)
		{
			ret = nl;
			last = ret;
		}
		else
		{
			last->next = nl;
			last = last->next;
		}
		cur = cur->next;
	}
	return (ret);
}
