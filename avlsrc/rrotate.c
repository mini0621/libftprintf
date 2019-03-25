/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:27:19 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/25 16:27:19 by sunakim          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_avl.h"

void	rrotate(t_tnode *top)
{
	t_tnode *tl;
	t_tnode *tlr;

	tl = top->l;
	tlr = tl->r;
	tl->r = top;
	top->l = tlr;
	top->h = ft_max(ft_avlheight(top->l), ft_avlheight(top->r)) + 1;
	tl->h = ft_max(ft_avlheight(tl->l), ft_avlheight(tl->r)) + 1;
}
