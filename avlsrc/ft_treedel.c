/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_treedel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 19:35:59 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/26 16:25:44 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl.h"

static void ft_nodedel(t_tnode *node, void (del)(void *))
{
	if (node != NULL)
	{
		ft_nodedel(node->l);
		ft_nodedel(node->r);
		del(node->cnt);
		free(node);
		node = NULL;
	}
}

void	ft_treedel(t_tnode **root, void (del)(void *))
{
	if (*root != NULL)
	{
		ft_nodedel(*root);
		del(root->cnt);
		free(*root);
		*root = NULL;
	}
}
