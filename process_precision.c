/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_precision.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/10 14:06:47 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/13 15:22:46 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_precision(char sp, char **s, int precision)
{
	char	*ret;

	if (precision == -1 || ft_strlen(*s) >= precision)
		return (*s);
	if ((ret = ft_strnew(precision)) == NULL)
	{
		free(*s);
		return (NULL);
	}
	ft_memset(ret, '0', (precision - ft_strlen(*s)) *sizeof(char));
	ft_strcat(ret, *s);
	free(*s);
	return (ret);
}

char	*prcs_precision_end(char sp, char **s, int precision)
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
