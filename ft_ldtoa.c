/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:21:57 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/09 23:32:51 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ldtoa(t_double *n, int precision)
{
	unsigned long long	*a;
	unsigned long long	*b;
	short		expo;
	char		*ret;

	expo = n->expo;
	if ((a = init_frac(n->frac, n->expo, 1)) == NULL)
		return (NULL);
	if ((b = init_frac(n->frac, n->expo, 0)) == NULL)
	{
		free(a);
		return (NULL);
	}
	if (expo > 0)
	{
		mult_frac(a, 10, 52);
		mult_frac(a, 2, (int)expo);
		mult_frac(b, 10, (int)expo);
		mult_frac(b, 5, (int)(52 - expo));
	}
	else
	{
		mult_frac(a, 5, 52);
		printf("a-1 %llu%llu%llu\n%llu%llu%llu\n%llu%llu%llu\n",a[18],a[17],a[16],a[15],a[14],a[13],a[12], a[11], a[10]);
		mult_frac(a, 2, 52 + (int)expo);
		printf("a-2 %llu%llu%llu\n%llu%llu%llu\n%llu%llu%llu\n",a[18],a[17],a[16],a[15],a[14],a[13],a[12], a[11], a[10]);
		mult_frac(b, 5, 52);
		printf("b-1 %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",b[18],b[17],b[16],b[15],b[14],b[13],b[12], b[11], b[10]);
		div_frac(b,(int)(-expo));
		printf("b-2 %llu %llu %llu %llu %llu %llu %llu %llu %llu\n",b[16],b[15],b[14],b[13],b[12], b[11], b[10], b[9], b[8]);
	}
	add_frac(a, &b);
	ret = fractoa(a);
	free(a);
	return (ret);
}

char	*fractoa(unsigned long long *frac)
{
	int	i;
	char *ret;
	char *s;

	i = 19;
	ret = ft_llutoa(frac[20], 10);
	printf("check : %s ", ret);
	while (i != 0)
	{
		s = ft_llutoa(frac[i], 10);
		printf("%s ", s);
		if ((ret = ft_strjoinfree(&ret, &s, 3)) == NULL)
			return (NULL);
		i--;
	}
	printf("\n");
	return (ret);
}
