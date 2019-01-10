/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:49:16 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/10 23:24:58 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	div_frac(unsigned long long *a, int times)
{
	int	i;
	int	e;
	unsigned long long c;
	unsigned long long tmp;
	
	e = 0;
	while (times != 0)
	{
//	printf("1 %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",a[17], a[16], a[15],a[14], a[13], a[12],a[11], a[10], a[9], a[8]);
		i = 100;
		c = 0;
		while (i != 0)
		{
			if (a[i] != 0)
			{
				tmp = a[i];
				a[i] /= 2;
				a[i] += c;
				if (tmp % 2 == 1)
					c = 50000000;
				else
					c = 0;
			}
			if (a[i] == 0)
			{
				a[i] += c;
				c = 0;
			}
			i--;
		}
//	printf("2 %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",a[17],  a[16], a[15],a[14], a[13], a[12],a[11], a[10], a[9], a[8]);
		carry_frac(a);
//	printf("3 %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",a[17], a[16], a[15],a[14], a[13], a[12],a[11], a[10], a[9], a[8]);
		times--;
	}
	return (e);
}

int		add_frac(unsigned long long *a, unsigned long long **b)
{
	int	i;
	int e;

	e = 0;
//	printf("a %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", a[18],a[17], a[16], a[15],a[14], a[13], a[12],a[11], a[10]);
//		printf("b %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",*(*b+18),*(*b+17),*(*b+16),*(*b+15), *(*b+14),*(*b+13),*(*b+12),*(*b+11),*(*b+ 10));
	i = 0;
	while (i < 101)
	{
		a[i] += *(*b + i);
		i++;
	}
	carry_frac(a);
//printf("l %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",  a[18],a[17], a[16], a[15],a[14], a[13], a[12],a[11], a[10]);
	free(*b);
	return (e);
}

int	mult_frac(unsigned long long *frac, int a, int times, int zero)
{
	int	i;
	int	e;
	int	index;

	e = 0;
	i = 0;
	while (i < times)
	{
		
//	printf("b %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", frac[18],frac[17], frac[16], frac[15],frac[14], frac[13], frac[12],frac[11], frac[10]);
		index = zero;
		while (index < 101)
		{
			frac[index] *= a;
			index++;
		}
//	printf("a %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", frac[18],frac[17], frac[16], frac[15],frac[14], frac[13], frac[12],frac[11], frac[10]);
		carry_frac(frac);
//	printf("c %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", frac[18],frac[17], frac[16] ,frac[15],frac[14], frac[13], frac[12],frac[11], frac[10]);
		i++;
	}
	return (e);
}

void	carry_frac(unsigned long long *frac10)
{
	int	i;
	unsigned long long c;

	i = 0;
	while (i < 100)
	{
		if (frac10[i] != 0)
		{
			c = frac10[i] / 100000000;
			frac10[i] %= 100000000;
		}
		else
			c = 0;
		frac10[i + 1] += c;
		i++;
	}
}

int	frac_expo(unsigned long long *frac)
{
	int	i;
	int tmp;

	i = 0;
	while (i < 50 && frac[i + 40] == 0)
		i++;
	if (i > 0)
	{
		tmp = 30;
		while (tmp + i < 60)
		{
			frac[tmp] = frac[tmp + i];
			tmp++;
		}
	}
	return (i);
}

int	frac_expo_min(unsigned long long *frac)
{
	int	i;
	int	tmp;

	i = 0;
	while (i < -30 && frac[30 - i] == 0)
		i++;
	if (i > 0)
	{
		tmp = 29;
		while (tmp - i > 0)
		{
			frac[tmp] = frac[tmp - i];
			tmp++;
		}
	}
	return (-i);	
}
