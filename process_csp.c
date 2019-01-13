/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_csp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 17:58:39 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/13 20:37:52 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_c(va_list *ap, t_printops *opt, size_t *l)
{
	char	c;
	char	*ret;
	char	*tmp;
	int		terminate;

	*l = 1;
	c = (char)va_arg(*ap, int);

	terminate = (c == '\0') ? 1:0;
	c = (terminate == 1) ? 'A':c;
	if ((ret = ft_strnew(1)) == NULL)
		return (NULL);
	ft_strncpy(ret, &c, 1);
	if (prcs_flags(opt, &ret, 0) == NULL)
		return (NULL);
	if (terminate == 1 && (tmp = ft_strchr(ret, 'A')) != NULL)
		*tmp = '\0';
	return (ret);
}

char	*prcs_s(va_list *ap, t_printops *opt, size_t *l)
{
	char	*s;
	char	*ret;

	s = va_arg(*ap, char *);
	if (s == NULL)
		ret = ft_strdup("(null)");
	else
		ret = ft_strdup(s);
	if (prcs_flags(opt, &ret, 0) == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
}

char	*prcs_p(va_list *ap, t_printops *opt, size_t *l)
{
	char		*ret;
	unsigned long long arg;

	arg = va_arg(*ap, unsigned long long);
	if ((ret = ft_llutoa(arg, 16)) == NULL)
		return (NULL);
	if (prcs_flags(opt, &ret, 0) == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
}
