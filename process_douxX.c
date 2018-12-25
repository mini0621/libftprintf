/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_diouxX.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:06:42 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/25 22:52:45 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*prcs_d(va_list *ap, t_printops *opt, size_t *l)
{
	t_lm		lm;
	char		*ret;
	long long	arg = 0;
	short i;
	
	lm = opt->lmod;
	//printf("lm = %i", lm);
	if (lm == 1)
		arg = (short)va_arg(*ap, int);
	else if (lm == 2)
		arg = (signed char)(va_arg(*ap, int));
	else if (lm == 3)
		arg = (long long)(va_arg(*ap, long));
	else if (lm == 4)
		arg = (long long)(va_arg(*ap, long long));
	else
		arg = (int)va_arg(*ap, int);

	printf("arg is %lld\n", arg);
	if ((ret = ft_lltoa(arg)) == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
}

char	*prcs_o(va_list *ap, t_printops *opt, size_t *l)
{
	//TODO
	//get argment
	//atoi + octal /decimal/ hex
	//change length
	//
	return (NULL);
}
char	*prcs_u(va_list *ap, t_printops *opt, size_t *l)
{
	return (NULL);
}

char	*prcs_x(va_list *ap, t_printops *opt, size_t *l)
{

	return (NULL);
}
