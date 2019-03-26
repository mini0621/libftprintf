/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avladd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:08:13 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/26 12:32:19 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl.h"

static void balAVL(t_tnode **root, t_tnode *new, void (*cmp)(void *, void *))
{
	int b;
	//get the balance
	b = balance((*root));
	// left left
	if (b > 1 && (cmp(new->cnt, (*root)->cnt)) < 0)
		rrotate((*root));
	// right right
	if (b < -1 && (cmp(new->cnt, (*root)->cnt)) > 0)
		lrotate((*root));
	//left right
	if (b > 1 && (cmp(new->cnt, (*root)->cnt)) > 0)
	{
		(*root)->l = lrotate((*root)->l);
		rrotate((*root));
	}
	//right left
	if (b < -1 && (cmp(new->cnt, (*root)->cnt)) < 0)
	{
		(*root)->r = rrotate((*root)->r);
		lrotate((*root));
	}
}

static int balance(t_tnode *n)
{
	if (n == NULL
		return 0;
	return (height(n->l) - height(n->r));
}

t_tnode	*ft_avladd(t_tnode **root, t_tnode *new, void (*cmp)(void *, void *))
{
	if (*root == NULL)
	{
		*root = new;
		return (*root)
	}
	if ((cmp(new->cnt, (*root)->cnt)) < 0)
		(*root)->l = ft_avladd(&((*root)->l), new, cmp);
	else if ((cmp(new->cnt, (*root)->cnt)) > 0)
		(*root)->r = ft_avladd(&((*root)->r), new, cmp);
	else
		ft_error(); // same keys ->error;
	//change height
	(*root)->h = 1 + ft_max(height((*root)->l, height((*root)->r)));
	*root = balAVL(root, new, cmp);
	//update all the change under the root
	return *root
}
