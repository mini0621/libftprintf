/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:38:25 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/13 15:50:15 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "prcsfs.h"

char	*convert(va_list *ap, char **start, size_t *l)
{
	t_printops *opt;
	t_prcs_fp	prcs;
	char		*ret;

	opt = readops(start);
	if (opt->cnvrtsp == '%')
		return (prcs_percent(opt, l));
	if ((prcs = getprcsf(opt)) == NULL)
		return (NULL);
	ret = (*prcs)(ap, opt, l);
	return (ret);
}

char	*prcs_percent(t_printops *opt, size_t *l)
{
	char	*ret;

	if ((ret = ft_strdup("%")) == NULL)
		return (NULL);
	prcs_flags(opt, &ret, 0);
	if (ret == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return(ret);
}

t_prcs_fp	getprcsf(t_printops *opt)
{
	t_prcs_fp	func;
	char		cs;
	int			i;

	cs = opt->cnvrtsp;
	i = 0;
	while (g_prcsfs[i].cnvrt_specifier != '\0')
	{
		if (g_prcsfs[i].cnvrt_specifier == cs )
			return (g_prcsfs[i].function);
		i++;
	}
	return (NULL);
}
