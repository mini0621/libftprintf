/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:49:16 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/09 23:32:45 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	div_frac(unsigned long long *a, int times)
{
	int	i;
	unsigned long long c;
	unsigned long long tmp;
	
	while (times != 0)
	{
	printf("1 %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",a[17], a[16], a[15],a[14], a[13], a[12],a[11], a[10], a[9], a[8]);
		i = 20;
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
	printf("2 %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",a[17],  a[16], a[15],a[14], a[13], a[12],a[11], a[10], a[9], a[8]);
		carry_frac(a);
	printf("3 %llu %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",a[17], a[16], a[15],a[14], a[13], a[12],a[11], a[10], a[9], a[8]);
		times--;
	}
}

void	add_frac(unsigned long long *a, unsigned long long **b)
{
	int	i;

	printf("a %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", a[18],a[17], a[16], a[15],a[14], a[13], a[12],a[11], a[10]);
		printf("b %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",*(*b+18),*(*b+17),*(*b+16),*(*b+15), *(*b+14),*(*b+13),*(*b+12),*(*b+11),*(*b+ 10));
	i = 0;
	while (i < 21)
	{
		a[i] += *(*b + i);
		i++;
	}
	carry_frac(a);
	printf("l %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", a[18],a[17], a[16], a[15],a[14], a[13], a[12],a[11], a[10]);
	free(*b);		
}

void	mult_frac(unsigned long long *frac, int a, int times)
{
	int	i;
	int	index;

	i = 0;
	while (i < times)
	{
		
	printf("b %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", frac[18],frac[17], frac[16], frac[15],frac[14], frac[13], frac[12],frac[11], frac[10]);
		index = 10;
		while (index < 21)
		{
			frac[index] *= a;
			index++;
		}
	printf("a %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", frac[18],frac[17], frac[16], frac[15],frac[14], frac[13], frac[12],frac[11], frac[10]);
		carry_frac(frac);
	printf("c %llu %llu %llu %llu %llu %llu %llu %llu %llu\n", frac[18],frac[17], frac[16] ,frac[15],frac[14], frac[13], frac[12],frac[11], frac[10]);
		i++;
	}
}
unsigned long long *init_frac(uint64_t frac, short expo, char flag)
{
	unsigned long long	*a;
	uint64_t			i;

	if ((a = (unsigned long long*)malloc(sizeof(unsigned long long) * 21)) == NULL)
		return (NULL);
	// 2^52 = 45035996 27370496
	// 	// 1 long holds 8 digits, max_long = 4,294,967,295
	// 		// where 99999999 * 10 can be stored
	// 			// this mean ret can hold 15 * 8 digits
	ft_bzero(a, sizeof(unsigned long long) * 21);
	if (flag == 1)
		i = 1;
	if (flag == 0)
		i = frac;
	printf("i is %llu\n", i);
	a[10] = i % 100000000;
	a[11] = i / 100000000;
	a[12] = i / 10000000000000000;
	carry_frac(a);
	printf("init frac is %llu%llu%llu\n", a[12],a[11], a[10]);
	return (a);
}

void	carry_frac(unsigned long long *frac10)
{
	int	i;
	unsigned long long c;

	i = 10;
	while (i < 20)
	{
		c = frac10[i] / 100000000;
		frac10[i] %= 100000000;
		frac10[i + 1] += c;
		i++;
	}
}
