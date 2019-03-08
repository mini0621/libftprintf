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

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "../includes/libftprintf.h"

typedef struct	s_tnode
{
	void			*content;
	struct s_tnode	*right;
	struct s_tnode	*left;
	struct s_tnode	*parent;
	int				height;
}				t_tnode;


t_tnode				*ft_avlnew(void const *content);
void				ft_avladd(t_tnode **root, t_tnode *new, void (*cmp)(void *, void *));
int					ft_avlheight();
void				rrotate(t_tnode *top);
void				lrotate(t_tnode *top);
t_tnode				*ft_avlfind(t_tnode **root, void *value, void (*cmp)(void *, void *));
void				ft_treedel(t_tnode **root, void (del)(void ));
endif
