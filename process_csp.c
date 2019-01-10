/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_csp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:58:39 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/10 14:55:23 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_c(va_list *ap, t_printops *opt, size_t *l)
{
	char	c;
	char	*ptr;

	*l = 1;
	c = (char)va_arg(*ap, int);
	if ((ptr = ft_strnew(1)) == NULL)
		return (NULL);
	ft_strncpy(ptr, &c, 1);
	return (ptr);
}

char	*prcs_s(va_list *ap, t_printops *opt, size_t *l)
{
	char	*s;

	s = va_arg(*ap, char *);
	*l = ft_strlen(s);
	return (ft_strdup(s));
}

char	*prcs_p(va_list *ap, t_printops *opt, size_t *l)
{
	//TODO
/*	char		*ret;
	unsigned long long arg;

	arg = va_arg(*ap, long long);
	printf("arg is %llu\n", arg);
	if ((ret = ft_llutoa(arg, 16)) == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
	*/
	return (NULL);
}
