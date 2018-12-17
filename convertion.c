/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convertion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 20:38:25 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/17 15:11:51 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*convert(va_list *ap, char **start, size_t *l)
{
	*start = *start + 2;
	//t_printops *opt;

	//*opt = readops(start);
	//look for the fuction
	// call t_cnvrt_fp function
	//change fmt function which depend on flang and min width
	char *s = ft_strnew(1);
	*s = '\0';
	*l = 1;		
	return (s);
}

t_prcs_fp	*getfuction(t_printops *opt)
{/*
	t_prcs_fp	func;
	char		cs;
	char		*lm;
	int			i;

	cs = opt->cnvrtsp;
	lm = opt->lmod;
	i = 0;
	while (prcsfs[i][1] == cnvrtsp && ft_strcmp(lmod,prcsfs[i][2]))
		i++;
	return (prcsfs[i][3]);
	*/
	return (NULL);
}
