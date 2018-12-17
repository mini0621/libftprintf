/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:55:20 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/17 14:13:03 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

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
	t_prcs_fp	function;
}				t_funcs;
/*
t_funcs	prcsfs[] = 
{
	{'d', "", &prcs_d},
	{'d', "h", &prcs_dh},
	{'d', "hh", &prcs_dhh},
	{'d', "l", &prcs_dl},
	{'d', "ll", &prcs_dll}
};
*/
int	ft_printf(const char *fmt, ...);
void printoutput(char *output, size_t len);
char	*join_chars(char **output, char *fmt, size_t *len);
char	*join_cnvrt(char **output, char **start, va_list *ap, size_t *len);
char	*convert(va_list *ap, char **start, size_t *l);
