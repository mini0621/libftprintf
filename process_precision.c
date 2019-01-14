/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:06:47 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/14 23:33:02 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_precision(char **s, size_t precision, int sign)
{
	char	*ret;

	if (precision == 0xffffffffffffffff || ft_strlen(*s) >= precision)
		return (*s);
	if ((ret = ft_strnew(precision + ft_strlen(*s))) == NULL)
	{
		free(*s);
		return (NULL);
	}
	if (sign < 0)
	{
		*ret = '-';		
		ft_memset(ret + 1, '0', (precision - ft_strlen(*s)) *sizeof(char));
		ft_strcpy(ret + precision + 1, *s + 1);
	}
	else
	{
		ft_memset(ret, '0', (precision - ft_strlen(*s)) *sizeof(char));
		ft_strcat(ret, *s);
	}
	free(*s);
	return (ret);
}

char	*prcs_precision_s(char **s, size_t precision)
{
	if (precision == 0)
	{
		**s = '\0';
		return (*s);
	}
	if (precision == 0xffffffffffffffff)
		return (*s);
	*s = ft_strsubfree(*s, 0, precision);
	return (*s);
}


char	*prcs_precision_end(char **s, size_t precision)
{
	char	*ret;

	if (ft_strlen(*s) >= precision)
		return (*s);
	if ((ret = ft_strnew(precision)) == NULL)
	{
		free(*s);
		return (NULL);
	}
	ft_strcat(ret, *s);
	ft_memset(ret + ft_strlen(*s), '0', (precision - ft_strlen(*s)) *sizeof(char));
	free(*s);
	return (ret);


}
