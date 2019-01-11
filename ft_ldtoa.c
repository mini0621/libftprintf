/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:21:57 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/11 19:30:32 by mnishimo         ###   ########.fr       */
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
	p = 0;
	if (n->frac != 0)
	{
		while (n->frac % 2 == 0)
		{
			n->frac = n->frac >> 1;
			p--;
		}
	}
	p = (short)ft_strlen(ret) - (52 + p - (n->expo));
	printf("p : %i", p);
	if (p < 0)
	{
		integer = ft_strnew(-p);
		ft_memset(integer, '0', -p);
		ret = ft_strjoinfree(&integer, &ret, 3);
		p = 0;
	}	
	if (precision != 0 && p + precision -1 < ft_strlen(ret))
		ret = round_ldchar(&ret, p + precision - 1);
	integer = sub_integer(ret, (int)p, precision);
	if (precision == 0)
	{
		integer = sub_integer(ret, (int)p, precision);
		free(ret);
		return (integer);
	}
	ret = ft_strsubfree(ret,(int)p, precision);
	if (ft_strlen(ret) < precision)
		ret = prcs_precision_end('d', &ret, precision);
	ret = ft_strjoinfree(&integer, &ret, 3);
	return (ret);
}

char	*round_ldchar(char **s, int index)
{
	char	*ret;

	if (*(*s + index + 1) < '5')
		return (*s);
	while (index != 0)
	{
		if (*(*s + index) != '9')
		{
			*(*s + index) += 1;
			return (*s);
		}
		*(*s + index) = '0';
		index--;
	}
	ret = ft_strdup("1");
	return (ft_strjoinfree(&ret, s, 3));
}

void	del_end0(char *s)
{
	int	i;
	int	min;
; 
	i = ft_strlen(s)- 1;
	min = 0;
	while (min < i  && s[min] == '0')
		min++;
	while (i > min + 52 && s[i] == '0')
	{
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
