/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avlfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 14:38:57 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/27 18:43:44 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_avl.h"

t_tnode	*ft_avlfind(t_tnode **root, void *value, int (*cmp)(void *, void *))
{
	t_tnode *p;

	if (*root == NULL)
		return (NULL);
	p = *root;
	while (p != NULL)
	{
		if ((cmp(value, p->cnt)) == 0)
			return (p);
		else if ((cmp(value, p->cnt)) < 0)
			p = p->l;
		else
			p = p->r;
	}
	return (NULL);
}
