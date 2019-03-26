/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avladd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:08:13 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/26 18:02:06 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl.h"

static int balance(t_tnode *n)
{
	if (n == NULL
		return 0;
	return (height(n->l) - height(n->r));
}

static void balAVL(t_tnode **root, t_tnode *new, void (*cmp)(void *, void *))
{
	int b;
	//get the balance
	b = balance((*root));
	// left left
	if (b > 1 && (cmp(new->cnt, (*root)->cnt)) < 0)
		*root = rrotate((*root));
	// right right
	if (b < -1 && (cmp(new->cnt, (*root)->cnt)) > 0)
		*root = lrotate((*root));
	//left right
	if (b > 1 && (cmp(new->cnt, (*root)->cnt)) > 0)
	{
		(*root)->l = lrotate((*root)->l);
		*root = rrotate((*root));
	}
	//right left
	if (b < -1 && (cmp(new->cnt, (*root)->cnt)) < 0)
	{
		(*root)->r = rrotate((*root)->r);
		*root = lrotate((*root));
	}
}

t_tnode	*ft_avladd(t_tnode **root, t_tnode *new, void (*cmp)(void *, void *))
{
	if (*root == NULL)	
	{
		*root = new;
		return (*root)
	}
	if ((cmp(new->cnt, (*root)->cnt)) < 0)
	{
		if (!((*root)->l = ft_avladd(&((*root)->l), new, cmp)))
		{
			ft_treedel(root);
			return (NULL);
		}
	}
	else if ((cmp(new->cnt, (*root)->cnt)) > 0)
	{
		if (!((*root)->r = ft_avladd(&((*root)->r), new, cmp)))
		{
			ft_treedel(root);
			return (NULL);
		}
	}
	else
		//delete everything and set
		ft_treedel(new);
		ft_treedel(root);
		return (NULL);
	//change height
	(*root)->h = 1 + ft_max(height((*root)->l, height((*root)->r)));
	balAVL(root, new, cmp);
	//update all the change under the root
	return *root;
}
