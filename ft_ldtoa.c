/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ldtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:21:57 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/12 00:28:34 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	get10th_expo(uint16_t expo)
{
	long double  p;
	int i;

	p = (short)(expo);
	p = (p * 0.301029999566L);
	printf("p is %Lf\n",p);
	i = (int)p;

	if (p == i)
		return (i);
	if (p > i)
		i = (i + 1 - p < p - i) ? i + 1:i;
	else
		i = (p - i + 1 < i - p) ? i - 1:i;
	return (i);

}
char	*ft_ldtoa(t_double *n, int precision)
{
	char	*ret;
	char	*integer;
	int		p;
	int		len;

	if ((ret = get_frac10(n)) == NULL)
		return (NULL);
//	printf("check :%s\n", ret);
	p = get10th_expo(n->expo);
	printf("p : %i\n", p);
	if (p >= 0)
		ret = ft_strsubfree(ret, skip_zeros(ret), p + precision);
	//printf("check2 :%s\n", ret);
	len = ft_strlen(ret);
	if (p < 0)
	{
		integer = ft_strnew(-p);
		ft_memset(integer, '0', -p);
		ret = ft_strjoinfree(&integer, &ret, 3);
		p = 0;
	}
	//printf("check3 :%s\n", ret);
	if (p > len)
	{
		integer = ft_strnew(p - len);
		ft_memset(integer, '0', p - len);
		ret = ft_strjoinfree(&ret, &integer, 3);
	}	

//	printf("check4 :%s\n", ret);
	if (p + precision < len)
		ret = round_ldchar(&ret, p + precision - 1);
//	printf("p : %i\n", p);
	integer = sub_integer(ret, p, precision);
//	printf("check5 ret:%s\ncheck5 int:%s\n", ret, integer);
	if (precision == 0)
	{
		free(ret);
		return (integer);
	}
	ret = ft_strsubfree(ret,(int)p + 1, precision);
	if (ft_strlen(ret) < precision)
		ret = prcs_precision_end('d', &ret, precision);
	ret = ft_strjoinfree(&integer, &ret, 3);
	return (ret);
}

char	*round_ldchar(char **s, int index)
{
	char	*ret;

	if (ft_strlen(*s) == index)
		return (*s);
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

int	skip_zeros(char *s)
{
	int	i;

	i = 0;
	while (s[i] == '0')
		i++;
	return (i);
}

char	*sub_integer(char *s, int point, int precision)
{
	int		i;
	char	*ret;
	char	*tmp;

	if (point == 0)
	{
		ret = ft_strnew(1);
		ret[0] = *s;
	}
	else if ((ret = ft_strsub(s, 0, point + 1)) == NULL)
		return (NULL);
	if (precision != 0)
	{
		tmp = ft_strdup(".");
		ret = ft_strjoinfree(&ret, &tmp, 3);
	}
	return (ret);
}
