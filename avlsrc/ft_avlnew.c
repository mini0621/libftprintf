/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:41:40 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/25 11:41:40 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl.h"

t_tnode	*ft_avlnew(void const *content)
{
	t_tnode *new;

	if(!(new = (t_tnode *)ft_memalloc(sizeof(t_tnode))))
		return (NULL); // or error
	new->cnt = content;
	new->l = NULL:
	new->r = NULL;
	new->prt = NULL; //?
	new->h = 1;
	return (new);
}
