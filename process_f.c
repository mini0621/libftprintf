/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:59:51 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/06 19:37:35 by mnishimo         ###   ########.fr       */
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
		arg = va_arg(*ap, long double);
	else
		arg = (long double)va_arg(*ap, double);
	printf("%Lf\n", arg);
	if ((ret = ft_ldtoa(arg, opt->precision)) == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
}

uint16_t	get_exponent(long double n)
{
	uint16_t c;
	ft_memset(&c, 0, 2);
	ft_memcpy(&c, &n, 2);
	printf("c is %04hx\n", c);
	return (c);
}

char *ft_ldtoa(long double n, int precision)
{
	uint16_t	expo;

	if ((expo = get_exponent(n)) == 0xffff)
		return (ft_strdup("-inf"));
	printf("expo is %i\n", expo);
	if (expo == 0x7fff)
		return (ft_strdup("inf"));
	if (expo == 0x0)
		return (ft_strdup("nan"));
	if (precision < 7 && n < 4294967295)
		return (ft_lditoa(n, precision));
return (NULL);	
}
