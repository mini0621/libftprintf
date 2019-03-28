/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sunakim <sunakim@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 18:20:14 by sunakim           #+#    #+#             */
/*   Updated: 2019/03/28 15:25:16 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVL_H
# define FT_AVL_H

# include "libftprintf.h"

typedef struct	s_tnode
{
	void			*cnt;
	struct s_tnode	*r;
	struct s_tnode	*l;
	struct s_tnode	*prt; // parent
	int				h;
}				t_tnode;

// many things to double check
t_tnode				*ft_avlnew(void const *content, size_t contentsize);
t_tnode				*ft_avladd(t_tnode **root, t_tnode *new, int (*cmp)(void *, void *),void (*del)(void *));
int					height (t_tnode* n);
t_tnode				*rrotate(t_tnode *top);
t_tnode				*lrotate(t_tnode *top);
t_tnode				*ft_avlfind(t_tnode *root, void *value, int (*cmp)(void *, void *));
void				ft_treedel(t_tnode **root, void (*del)(void *));

#endif
