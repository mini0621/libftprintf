/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:06:42 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/13 21:22:33 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int		ft_printf(const char *fmt, ...)
{
	char		*output;
	va_list		ap;
	size_t		l1;
	size_t		l2;
	char		*s;

	va_start(ap, fmt);
	l1 = 0;
	if ((fmt = join_chars(&output, fmt, &l1)) == NULL)
			return (-1)
	while (*fmt != '\0')
	{
		if ((s = convert(&ap, &fmt, &l2)) == NULL)
		{
			free(output);
			return (-1);
		}
		if ((output = ft_memjoinfree(&output, &s, l1, l2)) == NULL)
				return (-1);
		if ((fmt = join_chars(output, fmt)) == NULL)
			return(-1);
	}
	printoutput(&output, l1);
	return (0);
}

void printoutput(char **output, size_t len)
{
	write(1, output, len);
	ft_memdel(output);
}

char	*join_chars(char **output, char *fmt, size_t *len)
{
	char	*s;
	size_t	*i;

	//TODO
	i = 0;
	while(fmt[i] != '%' && fmt[i] != '\0')
		i++;
	if (i == 0)
		return (fmt + i);
	s = *output;
	if ((*output = ft_memalloc(l1 + l2 + 1)) == NULL)
	{
			free(s);
			return (NULL);
	}
	if (len != 0)
	{
		ft_memccpy(*output, s, l1);
		ft_memdel(s);
	}
	ft_memccpy(*output, fmt, i);
	return (fmt + i);
}

char	*memjoinfree(char **output, char **s, size_t l1, size_t l2)
{
	char	*ret;

	if ((ret = ft_memalloc(l1 + l2)) == NULL)
	{
		free(*output);
		return (NULL);
	}
	ft_memccpy(ret, *output, l1);
	ft_memccpy(ret, s, l2);
	ft_memdel(output);
	ft_memdel(s);
	return (ret);
}
