/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:06:42 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/17 15:11:28 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int		ft_printf(const char *fmt, ...)
{
	char		*output;
	va_list		ap;
	size_t		len;
	char		*start;

	va_start(ap, fmt);
	start = (char *)fmt;
	len = 0;
	if ((start = join_chars(&output, start, &len)) == NULL)
			return (-1);
	while (*start != '\0')
	{
		output = join_cnvrt(&output, &start, &ap, &len);
		if (output == NULL)
				return (-1);
		if ((start = join_chars(&output, start, &len)) == NULL)
			return(-1);
	}
	printoutput(output,len);
	return (0);
}

void printoutput(char *output, size_t len)
{
	write(1, output, len);
	free(output);
}

char	*join_chars(char **output, char *start, size_t *len)
{
	char	*s;
	size_t	i;

	i = 0;
	while(*(start + i) != '%' && *(start + i) != '\0')
		i++;
//	printf("i is %zu\n", i);
	if (i == 0)
		return (start);
	s = *output;
	if ((*output = ft_memalloc(*len + i + 1)) == NULL)
	{
			free(s);
			return (NULL);
	}
	if (*len != 0)
	{
		ft_memcpy(*output, s, *len);
		free(s);
	}
	ft_memcpy(*output + *len, start, i);
	*len += i;
	//printf("output is %s, start is at %s\n", *output, start);
	return (start + i);
}

char	*join_cnvrt(char **output, char **start, va_list *ap, size_t *len)
{
	char	*ret;
	char	*s;
	size_t	slen;

	s = convert(ap, start, &slen);
	if (s == NULL || (ret = ft_memalloc(*len + slen + 1)) == NULL)
	{
		free(*output);
		return (NULL);
	}
	ft_memcpy(ret, *output, *len);
	ft_memcpy(ret + *len, s, slen);
	//printf("ret is %s, len is %zu, slen is %zu\n", ret,*len, slen);
	//printf("output is %s, start is at %s\n", *output, *start);
	*len += slen;
	free(*output);
	free(s);
	return (ret);
}
