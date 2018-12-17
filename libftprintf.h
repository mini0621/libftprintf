/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:55:20 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/13 19:16:52 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>

typedef struct	s_printops
{
	char	flag;
	int		width;
	int		prescision;
	char	*lmod;
	char	cnvrtsp;
}				t_printops;

typedef char *(*t_prcs_fp)(va_list *, t_printops, int *);

typedef struct	s_funcs
{
	char		cnvrt_specifier;
	char		*length_modifier;
	t_cnvrt_fp	function;
}				t_funcs;

t_funcs	prcsfs[] = 
[
	{'d', "", &prcs_d},
	{'d', "h", &prcs_dh},
	{'d', "hh", &prcs_dhh},
	{'d', "l", &prcs_dl},
	{'d', "ll", &prcs_dll}
];
int	printf(const char *fmt, ...);
