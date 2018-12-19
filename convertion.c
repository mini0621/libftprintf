/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:38:25 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/19 19:33:36 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

char	*convert(va_list *ap, char **start, size_t *l)
{
	t_printops *opt;
	t_prcs_fp	prcs;
	char		*ret;

	opt = readops(start);
	prcs = getprcsf(opt);
	ret = (*prcs)(ap, opt, l);
	printf("converted\nret is %s, len is %zu\n", ret, *l);
	return (ret);
	// call t_cnvrt_fp function
	//change fmt function which depend on flang and min width
	
	
}

t_prcs_fp	getprcsf(t_printops *opt)
{/*
	t_prcs_fp	func;
	char		cs;
	int			i;

	cs = opt->cnvrtsp;
	i = 0;
	while (prcsfs[i][1] == cnvrtsp && ft_strcmp(lmod,prcsfs[i][2]))
		i++;
	return (prcsfs[i][3]);
	return (NULL);
	*/
	return (&prcs_d);
}
