/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 11:41:40 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/26 18:20:11 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl.h"

t_tnode	*ft_avlnew(void const *content, size_t contentsize)
{
	t_tnode *new;

	if(!(new = (t_tnode *)ft_memalloc(sizeof(t_tnode))))
		return (NULL);
	//if content == NULL
	//new->cnt = NULL
	//else
	//new->cnt = malloc
	//then
	//memcpy
	new->cnt = content;
	new->l = NULL:
	new->r = NULL;
	new->prt = NULL;
	new->h = 1;
	return (new);
}
