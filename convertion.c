/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:38:25 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/05 21:43:30 by mnishimo         ###   ########.fr       */
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
	{
		*l = 1;
		return (ft_strdup("%"));
	}
	if ((prcs = getprcsf(opt)) == NULL)
		return (NULL);
	ret = (*prcs)(ap, opt, l);
	return (ret);
}

t_prcs_fp	getprcsf(t_printops *opt)
{
	t_prcs_fp	func;
	char		cs;
	int			i;

	cs = opt->cnvrtsp;
	i = 0;
	while (prcsfs[i].cnvrt_specifier != '\0')
	{
		if (prcsfs[i].cnvrt_specifier == cs )
			return (prcsfs[i].function);
		i++;
	}
	return (NULL);
}
