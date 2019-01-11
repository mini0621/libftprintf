/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:59:51 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/12 00:37:46 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_f(va_list *ap, t_printops *opt, size_t *l)
{
	long double	arg;
	char		*ret;
	t_lm		lm;
	int			sign;

	lm = opt->lmod;
	ret = NULL;
	if (lm == 5)
		ret = prcs_ld(ap, opt, &sign);
	else
		ret = prcs_db(ap, opt, &sign);
	ret = prcs_flags(opt, &ret, sign);
	if (ret == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
}

char	*prcs_db(va_list *ap, t_printops *opt, int *sign)
{
	double	arg;
	t_double	*n;
	char	*ret;
	char	*s;

	arg = va_arg(*ap, double);
	n = get_double(arg);
	*sign = (arg == 0) ?  0:n->sign;
	printf("n is... sign:%d, expo is %hd, and fra is %lld\n", n->sign, n->expo, n->frac);
	if (n->expo == 1024)
		ret = sp_double(n->sign ,n->frac);
	else if ((opt->precision < 7 && arg < 100000000 && arg > -10000000))
		ret = ft_ldtolltoa((long double)arg, opt->precision);
	else
		ret = ft_ldtoa(n, opt->precision);
	if (*sign < 0)
	{
		s = ft_strdup("-");
		ret = ft_strjoinfree(&s, &ret, 3);
	}
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

char	*sp_double(int sign, uint64_t frac)
{
	if (frac != 0)
		return (ft_strdup("nan"));
	else if (sign > 0)
		return (ft_strdup("inf"));
	return (ft_strdup("-inf"));
}

