/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dl.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/27 21:56:41 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/05 22:30:23 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

long double	ft_ldpower(int  base, int power)
{
	if (power == 0)
		return (1.0L);
	if (power < 0)
		return (ft_neg_power(power));
	return ((long double)base * ft_power(base, power - 1));
}

int	max_fac(long double n)
{
	long double a;
	int	i;

	i = -1;
	a = 1;
	while (a < n)
	{
		a = a * 10;
		i++;
	}
	return (i);
}

long double getintdl(long double n, char **integer)
{
	int i;
	long double	power;
	char d;
	int index;

	i = max_fac(n);
	index = 0;
	if ((*integer = ft_strnew(i)) == NULL)
			return (0);
	while (i > 0)
	{
		d = '0';
		power = ft_ldpower(10, i);
		while (power < n)
		{
			n = n - power;
			d++;
		}
		*(*integer + index) = d;
	//printf("i is %d, power is %Lf, d is %c, index is %d\n", i, power, d, index);
		index++;
		i--;
	}
	return (n);
}
