/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 21:56:41 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/06 19:37:38 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long double ft_neg_power(int power)
{
	if (power <= 0)
		return (1);
	return (0.1 * ft_neg_power(power -1));
}

long double round_ld(long double n, int precision)
{
	int i;
	int d;
	long double	ret;

	ret = n;
	n = n - (long double)(long long)n;
	i = 0;
	while (i <= precision)
	{
		n *= 10;
		d = (int)n % 10;
		i++;
	}
	if (d > 4)
		ret = ret + ft_neg_power(precision);
	return (ret);
	
	
}

long double removeint(long double n, int precision, char **integer)
{
	char *s;

	if (n < 0)
	{
		n = -n;
		n = round_ld(n, precision);
		*integer = ft_llutoa((unsigned long long)n, 10);
		s = ft_strdup("-");
		*integer = ft_strjoinfree(&s, integer, 3);
		return (n - (unsigned long long)n);
	}
	n = round_ld(n, precision);
	*integer = ft_llutoa((unsigned long long)n, 10);
	return (n - (unsigned long long)n);

}

char	*ft_lditoa(long double n, int precision)
{
	char	*integer;
	int		i;
	char	*ret;

	n = removeint(n, precision, &integer);
	if (precision == 0)
		return (integer);
	i = 1;
	if ((ret = ft_strnew(precision + 1))== NULL)
		return (0);
	ret[0] = '.';
	while(i <= precision)
	{
		n = n * 10;
		ret[i] = (int)n + '0';
		n = n - (int)n;
		i++;
	}
	return (ft_strjoinfree(&integer, &ret, 3));
}
