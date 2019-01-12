/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 10:20:38 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/12 22:23:57 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_strjoinfree(char **s1, char **s2, int i)
{
	char	*ptr;

	if (s1 == NULL || s2 == NULL || *s1 == NULL || *s2 == NULL)
		return (NULL);
	ptr = ft_strnew(ft_strlen(*s1) + ft_strlen(*s2) + 1);
	if (ptr != NULL)
	{
		ft_strcat(ptr, *s1);
		ft_strcat(ptr, *s2);
	}
	if (i == 1 || i == 3)
		ft_strdel(s1);
	if (i == 2 || i == 3)
		ft_strdel(s2);
	return (ptr);
}
