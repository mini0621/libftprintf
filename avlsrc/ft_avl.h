/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_avl.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <mnishimo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/08 16:20:41 by mnishimo          #+#    #+#             */
/*   Updated: 2019/03/08 16:37:06 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_AVL_H
# define FT_AVL_H

# include "../includes/libftprintf.h"
# include "../includes/lemin.h"

typedef struct	s_tnode
{
	void			*cnt;
	struct s_tnode	*r;
	struct s_tnode	*l;
	struct s_tnode	*prt; // parent
	int				h;
}				t_tnode;


int					ft_max(int a, int b);
t_tnode				*ft_avlnew(void const *content);
void				ft_avladd(t_tnode **root, t_tnode *new, void (*cmp)(void *, void *));
int					ft_avlheight();
void				rrotate(t_tnode *top);
void				lrotate(t_tnode *top);
t_tnode				*ft_avlfind(t_tnode **root, void *value, void (*cmp)(void *, void *));
void				ft_treedel(t_tnode **root, void (del)(void *));
#endif
