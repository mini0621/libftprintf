/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qappend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:12:04 by mnishimo          #+#    #+#             */
/*   Updated: 2019/04/16 16:21:16 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_queue	*ft_qappend(t_queue *q, t_list *nl)
{
	t_list	*cur;

	if (!q || !nl)
		return (NULL);
	cur = q->top;
	if (!(q->top))
		q->top = nl;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = nl;
	}
	q->last = nl;
	return (q);
}
