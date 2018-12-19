/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:55:20 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/19 18:45:35 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include "libft/libft.h"
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

typedef enum	e_lm
{
	none = 0,
	h,
	hh,
	l,
	ll,
	L
}				t_lm;

typedef struct	s_flags
{
	char	sharp;
	char	min_0;
	char	plus_sp;
}				t_flags;

typedef struct	s_printops
{
	t_flags	flag;
	int		width;
	int		precision;
	t_lm	lmod;
	char	cnvrtsp;
}				t_printops;

typedef char *(*t_prcs_fp)(va_list *, t_printops *, size_t *);

typedef struct	s_funcs
{
	char		cnvrt_specifier;
	t_prcs_fp	function;
}				t_funcs;




int		ft_printf(const char *fmt, ...);
void	printoutput(char *output, size_t len);
char	*join_chars(char **output, char *fmt, size_t *len);
char	*join_cnvrt(char **output, char **start, va_list *ap, size_t *len);
char	*convert(va_list *ap, char **start, size_t *l);
t_prcs_fp	getprcsf(t_printops *opt);
int is_cnvrtsp(char c);
t_printops	*initoption(void);
t_printops	*readops(char **start);
void		storeops(char **start, int i, t_printops *opt);
char	*prcs_g(va_list *ap, t_printops *opt, size_t *l);
char	*prcs_e(va_list *ap, t_printops *opt, size_t *l);
char	*prcs_x(va_list *ap, t_printops *opt, size_t *l);
char	*prcs_o(va_list *ap, t_printops *opt, size_t *l);
char	*prcs_u(va_list *ap, t_printops *opt, size_t *l);
char	*prcs_d(va_list *ap, t_printops *opt, size_t *l);
char	*prcs_p(va_list *ap, t_printops *opt, size_t *l);
char	*prcs_s(va_list *ap, t_printops *opt, size_t *l);
char	*prcs_c(va_list *ap, t_printops *opt, size_t *l);
char	*prcs_f(va_list *ap, t_printops *opt, size_t *l);
char	*ft_lltoa(long long n);
#endif 
