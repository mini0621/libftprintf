/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:27:39 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/25 16:27:39 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl.h"

void	lrotate(t_tnode *top)
{
	t_tnode *tr;
	t_tnode *trl;

	tr = top->r;
	trl = tr->l;
	tr->l = top;
	top->r = trl;
	top->h = ft_max(ft_avlheight(top->l), ft_avlheight(top->r) + 1);
	tr->h = ft_max(ft_avlheight(tr->l), ft_avlheight(tr->r) + 1);
}
