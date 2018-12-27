/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:38:25 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/27 23:25:03 by mnishimo         ###   ########.fr       */
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
	if ((prcs = getprcsf(opt)) == NULL)
		return (NULL);
	ret = (*prcs)(ap, opt, l);
	printf("converted\nret is %s, len is %zu\n", ret, *l);
	return (ret);
	
}

t_prcs_fp	getprcsf(t_printops *opt)
{
	t_prcs_fp	func;
	char		cs;
	int			i;

	cs = opt->cnvrtsp;
	printf("cs is %c\n", cs);
	printf("precision is %i\n", opt->precision);
	i = 0;
	while (prcsfs[i].cnvrt_specifier != '\0')
	{
		if (prcsfs[i].cnvrt_specifier == cs )
			return (prcsfs[i].function);
		i++;
	}
	return (NULL);
}
