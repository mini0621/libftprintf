/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avladd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 15:08:13 by sunakim           #+#    #+#             */
/*   Updated: 2019/04/02 19:53:13 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "../includes/ft_avl.h"

static int balance(t_tnode *n)
{
	if (n == NULL)
		return (0);
	return (height(n->l) - height(n->r));
}

static void balavl(t_tnode **root, t_tnode *new, int (*cmp)(void *, void *))
{
	int b;
	//get the balance
	b = balance((*root));
	// left left
	if (b > 1 && (cmp(new->cnt, (*root)->cnt)) < 0)
		*root = rrotate((*root));
	// right righ
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

t_tnode	*ft_avladd(t_tnode **root, t_tnode *new, int (*cmp)(void *, void *), void (*del)(void *))
{
	if (*root == NULL)	
	{
		*root = new;
		return (*root);
	}
	if ((cmp(new->cnt, (*root)->cnt)) < 0)
	{
		if (!((*root)->l = ft_avladd(&((*root)->l), new, cmp, del)))
		{
			ft_treedel(root, del);
			return (NULL);
		}
	}
	else if ((cmp(new->cnt, (*root)->cnt)) > 0)
	{
		if (!((*root)->r = ft_avladd(&((*root)->r), new, cmp, del)))
		{
			ft_treedel(root, del);
			return (NULL);
		}
	}
	else
	{
		//delete everything and set
		ft_treedel(&new, del);
		ft_treedel(root, del);
		return (NULL);
	}
	//change height
	(*root)->h = 1 + ft_max(height((*root)->l), height((*root)->r));
	balavl(root, new, cmp);
	//update all the change under the root
	return *root;
}
