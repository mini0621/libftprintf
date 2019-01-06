/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 21:56:41 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/05 22:29:57 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
long double	ft_neg_power(int power)
{
	if (power == 0)
		return (1);
	return (0.1 * ft_neg_power(power - 1));
}

char		get_n_dig(long double n)
{
	n = n - (long double)(long long)n;
	n = n * 10;
	return ((int)n + '0');

}

long double	get_exponent(long double n)
{
	long double			d;

	d = 0;
	while (n >= 1)
	{
		n = n - 1;
		d = d + 1;
	}
	return (d);

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

char	*ft_dltoa(long double n, int precision)
{
	char	*integer;
	int		i;
	char	*ret;
	int		digit;

	n = round_ld(n, precision);
	integer = ft_itoa((long long)n);
	n = n - get_exponent(n);
	if (precision == 0)
		return (integer);
	i = 1;
	if ((ret = ft_strnew(precision + 1))== NULL)
		return (0);
	ret[0] = '.';
	while(i <= precision)
	{
	//	printf("i is %d\ntimes ten is %.200Lf\n", i,n);
		ret[i] = get_n_dig(n);
		n = n * 10;
		i++;
	}
	return (ft_strjoinfree(&integer, &ret, 3));
}

