/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qappend.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 22:12:04 by mnishimo          #+#    #+#             */
/*   Updated: 2019/05/17 18:07:01 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_queue	*ft_qappend(t_queue *q, t_list *nl)
{
	if (!q || !nl)
		return (NULL);
	if (!(q->top))
		q->top = nl;
	if (q->last)
	{
		q->last->next =  nl;
		q->last = nl;
	}
	else
		q->last = nl;
	return (q);
}
