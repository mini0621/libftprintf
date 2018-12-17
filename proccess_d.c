/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_d.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:06:42 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/13 21:22:33 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_d(va_list *ap, t_printops *opt, size_t *l)
{
	int		i;
	char	*ret;

	//TODO
	i = va_arg(ap, int);
	if ((ret = itoa(i)) == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
}

char	*prcs_dh(va_list *ap, t_printops opt, size_t *l)
{
	//TODO
	//get argment
	//atoi + octal /decimal/ hex
	//change length
	//
	return (NULL);
}
