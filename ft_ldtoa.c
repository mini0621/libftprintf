/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:21:57 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/12 22:02:35 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get10th_expo(uint16_t expo)
{
	long double  p;
	int i;

	p = (short)(expo);
	p = (p * 0.301029999566L);
//	printf("p is %Lf\n",p);
	i = (int)p;

	if (p == i)
		return (i);
	if (p > i)
		i = (i + 1 - p < p - i) ? i + 1:i;
	else
		i = (p - i + 1 < p - 1) ? i - 1:i;
	return (i);

}

char	*ft_ldtoa(t_double *n, int precision)
{
	char	*ret;
	char	*integer;
	int		p;

	if ((ret = get_frac10(n, 63, 0)) == NULL)
		return (NULL);
	//printf("check :%s\n", ret);
	p = get10th_expo(n->expo) + 1;
	ret = ft_strsubfree(ret, skip_zeros(ret), p + precision + 1);
	//printf("check2 :%s\n", ret);
	//printf("p : %i\n", p);
	integer = sub_integer(&ret, p, precision);
	if (precision == 0)
		return (integer);
//	printf("check3 :%s\n", ret);	
	ret = ft_strsubfree(ret, 0, precision);
	if (ft_strlen(ret) < precision)
		ret = prcs_precision_end('d', &ret, precision);
//	printf("check5 ret:%s\ncheck5 int:%s\n", ret, integer);
	ret = ft_strjoinfree(&integer, &ret, 3);
	return (ret);
}

int round_s(char **s, int	point, int precision)
{
	int	index;

	index =  (point < 0) ? precision : point + precision;
	if (ft_strlen(*s) <= index + 1)
		return (0);
	if (*(*s + index + 1) < '5')
		return (0);
	while (index != 0)
	{
		if (*(*s + index) != '9')
		{
			*(*s + index) += 1;
			return (0);
		}
		*(*s + index) = '0';
		index--;
	}
	if (index == 0)
		return (1);
	return (0);
}

int	skip_zeros(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '0')
		i++;
	return (i);
}

char	*sub_integer(char **s, int point, int precision)
{
	int		i;
	char	*ret;
	char	*tmp;

	if (point < 0)
	{
		tmp = ft_strnew(-point);
		ft_memset(tmp, '0', -point);
		*s = ft_strjoinfree(&tmp, s, 3);
	}
	if (round_s(s, point, precision) == 1)
		ret = ft_strdup("1");
	else if (point == 0)
		ret = ft_strdup("0");
	else if ((ret = ft_strsub(*s, 0, point)) == NULL)
		return (NULL);
	if (precision != 0)
	{
		tmp = ft_strdup(".");
		ret = ft_strjoinfree(&ret, &tmp, 3);
	}
	else
		free(*s);
	return (ret);
}
