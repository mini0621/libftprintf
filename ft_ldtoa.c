/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:21:57 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/10 23:24:56 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_ldtoa(t_double *n, int precision)
{
	char	*ret;
	char	*integer;
	short	p;

	if ((ret = get_frac10(n)) == NULL)
		return (NULL);
	printf("check %s\n", ret);
	p = 0;
	while (n->frac % 2 == 0)
	{
		n->frac = n->frac >> 1;
		p--;
	}
	p = ft_strlen(ret) - (52 + p - (short)(n->expo));
	printf("p : %i", p);
	if (p < 0)
		p = 0;	
	integer = sub_integer(ret, (int)p, precision);
	if (precision == 0)
	{
		free(ret);
		return (integer);
	}
	if (p > 0)
		ret = ft_strsubfree(ret,(int)p, precision);
	else
	{
		free(ret);
		ret = ft_strnew(0);
	}
	if (ft_strlen(ret) < precision)
		ret = prcs_precision_end('d', &ret, precision);
	ret = ft_strjoinfree(&integer, &ret, 3);
	return (ret);
}

void	del_end0(char *s)
{
	int	i;

	i = ft_strlen(s) - 1;
	while (i != 0)
	{
		if (s[i] != '0')
			return;
		s[i] = '\0';
		i--;
	}
}

char	*sub_integer(char *s, int point, int precision)
{
	int		i;
	char	*ret;
	char	*tmp;

	i = 0;
	while (i < point && s[i] == '0')
		i++;
	if (i == point)
		ret = ft_strdup("0");
	else if ((ret = ft_strsub(s, i, point - i)) == NULL)
			return (NULL);
	if (precision != 0)
	{
		tmp = ft_strdup(".");
		ret = ft_strjoinfree(&ret, &tmp, 3);
	}
	return (ret);
}
