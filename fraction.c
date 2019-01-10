/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fraction.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 18:49:16 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/10 23:24:54 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

unsigned long long *init_frac(uint64_t frac, short expo, int zero)
{
	unsigned long long	*a;
	uint64_t			i;

	if ((a = (unsigned long long*)malloc(sizeof(unsigned long long) * 101)) == NULL)
		return (NULL);
	// 2^52 = 45035996 27370496
	// 	// 1 long holds 8 digits, max_long = 4,294,967,295
	// 		// where 99999999 * 10 can be stored
	// 			// this mean ret can hold 15 * 8 digits
	i = 4503599627370496;

	ft_bzero(a, sizeof(unsigned long long) * 101);
	a[zero] = i % 100000000 + frac % 100000000;
	a[zero + 1] = i / 100000000 + frac / 100000000;
	a[zero + 2] = frac / 10000000000000000;
	carry_frac(a);
	//	printf("init frac is %llu%llu%llu\n", a[12],a[11], a[10]);
	return (a);
}

char	*get_frac10(t_double *n)
{
	unsigned long long	*a;
	short		expo;
	int			zero;

	expo = n->expo;
	zero = (expo >= 0) ? 10:90;
		a = init_frac(n->frac, n->expo, zero);
	if (a == NULL)
		return (NULL);
	mult_frac(a, 5, 52, zero);
	if (expo > 0)
		mult_frac(a, 2, (int)expo, zero);
	else
		div_frac(a,(int)(-expo));
	return (fractoa(a));
}

char	*fractoa(unsigned long long *frac)
{
	int	i;
	char *ret;
	char *s;

	i = 99;
	ret = ft_llutoa(frac[100], 10);
	ret = prcs_precision( 'd', &ret, 8);
	while (i < 100 && frac[i] != 0)
		i++;
	while (i != 0)
	{
		s = ft_llutoa(frac[i], 10);
		s = prcs_precision( 'd', &s, 8);
		printf("%s ", s);
		if ((ret = ft_strjoinfree(&ret, &s, 3)) == NULL)
			return (NULL);
		i--;
	}
	printf("\n");
	del_end0(ret);
	free(frac);
	return (ret);
}
