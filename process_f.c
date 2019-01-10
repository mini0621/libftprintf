/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:59:51 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/11 00:23:46 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_f(va_list *ap, t_printops *opt, size_t *l)
{
	long double	arg;
	char		*ret;
	t_lm		lm;
	lm = opt->lmod;

	ret = NULL;
	if (lm == 5)
		ret = prcs_ld(ap, opt);
	else
		ret = prcs_db(ap, opt);
	if (ret == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
}

char	*prcs_ld(va_list *ap, t_printops *opt)
{
	long double	arg;
	t_double	*n;
	t_lm		lm;
	//take fra and exp and check if -inf and inf and Nan
	//nan is when exp == 0x7fff and fra isnot 0
	//-inf is exp == 0xffff (and fra is 0?)
	//is nan with exp == 0xffff is a nan? 
	arg = va_arg(*ap, long double);
	n = get_ldouble(arg);
	printf("ld is... sign:%i, expo is %hd, and fra is %llx\n", n->sign, n->expo, n->frac);
	free(n);
	if (opt->precision < 7 && arg < 100000000 && arg >-10000000)
		return(ft_ldtolltoa(arg, opt->precision));
	return (NULL);
}

char	*prcs_db(va_list *ap, t_printops *opt)
{
	double	arg;
	t_double	*n;
	t_lm	lm;
	char	*ret;


	arg = va_arg(*ap, double);
	n = get_double(arg);
	printf("n is... sign:%d, expo is %hd, and fra is %lld\n", n->sign, n->expo, n->frac);
	if (opt->precision < 7 && arg < 100000000 && arg > -10000000)
		ret = ft_ldtolltoa((long double)arg, opt->precision);
	else
		ret = ft_ldtoa(n, opt->precision);
	free(n);
	return(ret);
}

t_double	*get_double(double n)
{
	t_double *d;
	uint16_t c;


	if ((d = (t_double *)malloc(sizeof(t_double))) == NULL)
		return (NULL);
	if ((c = *((uint16_t*)&n + 3)) > 0x7fff)
		d->sign = -1;
	else
		d->sign = 1;
	//printf("first 16 bit is %04hx\n", c);
	printf("first 16 bit is %04x\n", c >> 4);
	d->expo = (((c & 0x7fff) >> 4 ) - 1023);
	d->frac = *((uint64_t*)&n);
	d->frac = d->frac & 0x000fffffffffffff;
	printf("63bit: %llx\n", d->frac);
	return (d);
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
//if (c == 0x7fff || c == 0xffff)
