/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:59:51 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/11 19:20:14 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_ld(va_list *ap, t_printops *opt, int *sign)
{
	long double	arg;
	t_double	*n;
	t_lm		lm;
	char		*ret;
	
	arg = va_arg(*ap, long double);
	n = get_ldouble(arg);
	free(n);
	if (opt->precision < 7 && arg < 100000000 && arg >-10000000)
		return(ft_ldtolltoa(arg, opt->precision));
	else if (n->expo == 1024)
		ret = sp_double(n->sign ,n->frac);
	else
		ret = ft_ldtoa(n, opt->precision);
	return (NULL);
}

t_double	*get_ldouble(long double n)
{
	t_double *d;
	uint16_t c;


	if ((d = (t_double *)malloc(sizeof(t_double))) == NULL)
		return (NULL);
	if ((c = *((uint16_t*)&n + 4)) > 0x7fff)
		d->sign = -1;
	else
		d->sign = 1;
	printf("first 16 bit is %04hx\n", c);
	d->expo = (c & 0x7fff) - 0x3fff;
	d->frac = *((uint64_t*)&n);
	return (d);
}
