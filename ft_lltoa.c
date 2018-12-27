/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:47:00 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/27 19:58:50 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft/libft.h"

long long	ft_llpower(long long base, long long power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (1);
	return (base * ft_power(base, power - 1));
}

char		*ft_lltoa(long long n)
{
	char	*ptr;
	long long	i;
	long long	neg;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	neg = (n < 0) ? 1 : 0;
	n = (n < 0) ? -n : n;
	while (n / ft_llpower(10, i) != 0)
		i++;
	if ((ptr = ft_strnew(i + neg)) == NULL)
		return (NULL);
	i = i + neg - 1;
	while (i >= neg)
	{
		ptr[i] = n % 10 + '0';
		n = n / 10;
		i--;
	}
	if (neg == 1)
		ptr[0] = '-';
	return (ptr);
}

char	*create_base(unsigned int base)
{
	char	*ret;

	if (base > 16)
		return (NULL);
	if((ret = ft_strnew(base)) == NULL)
		return (NULL);
	ft_strncpy(ret, "0123456789abcdef", base * sizeof(char));
	return (ret);
}

unsigned long long	ft_llupower(unsigned long long base, long long power)
{
	if (power == 0)
		return (1);
	if (power < 0)
		return (1);
	return (base * ft_power(base, power - 1));
}

char		*ft_llutoa(unsigned long long n, unsigned int base)
{
	char	*ptr;
	unsigned long long	i;
	char	*rep;

	i = 0;
	if (n == 0)
		return (ft_strdup("0"));
	if ((rep = create_base(base)) == NULL)
		return (NULL);
	while (n / ft_llpower(base, i) != 0)
		i++;
	if ((ptr = ft_strnew(i)) == NULL)
		return (NULL);
	i = i - 1;
	while ((int)i > -1)
	{
		ptr[i] = rep[n % base];
		n = n / base;
		i--;
	}
	free(rep);
	return (ptr);
}
