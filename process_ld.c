/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:59:51 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/13 01:24:56 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_ld(va_list *ap, t_printops *opt, int *sign)
{
	long double	arg;
	t_double	*n;
	char		*s;
	char		*ret;

	arg = va_arg(*ap, long double);
	if ((n = get_ldouble(arg)) == NULL)
		return (NULL);
	*sign = (arg == 0) ? 0:n->sign;
//	printf("n is... sign:%d, expo is %hd, and fra is %llu\n", n->sign, n->expo, n->frac);
	if (n->expo == 0xefff)
		ret = sp_double(n->sign ,n->frac);
	else if (arg == 0 || (opt->precision < 7 && arg < 100000000 && arg >-10000000))
		ret = ft_ldtolltoa(arg, opt->precision);
	else
		ret = ft_ldtoa(n, opt->precision, 0);
	if (*sign < 0)
	{
		s = ft_strdup("-");
		ret = ft_strjoinfree(&s, &ret, 3);
	}
	free(n);
	return (ret);
}

t_double	*get_ldouble(long double n)
{
	t_double *d;
	uint16_t c;


	if ((d = (t_double *)malloc(sizeof(t_double))) == NULL)
		return (NULL);
	if ((c = *((uint16_t*)&n + 4)) > 0xefff)
		d->sign = -1;
	else
		d->sign = 1;
	//printf("first 16 bit is %04hx\n", c);
	d->expo = (c & 0x7fff) - 16383;
	d->frac = *((uint64_t*)&n);
	//printf("frac = %llx\n", d->frac);
	return (d);
}
