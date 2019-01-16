/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:57:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/16 00:58:25 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int			is_cnvrtsp(char c)
{
	if (c == 'i' || c == 'd' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
	|| c == 'c' || c == 'f' || c == 's' || c == 'p' || c == 'e' || c == '%')
		return (1);
	if (c != 'l' && c != 'h' && c != '.' && c != 'L' && c != ' '
		&& c != ' ' && c != '#' && c != '-' && c != '+'
		&& ft_isdigit(c) == 0 && c != 'j')
		return (-1);
	return (0);
}

t_printops	*initoption(void)
{
	t_printops	*opt;

	if ((opt = (t_printops *)malloc(sizeof(t_printops))) == NULL)
		return (NULL);
	opt->flag.sharp = '\0';
	opt->flag.min_0 = '\0';
	opt->flag.plus_sp = '\0';
	opt->width = 0;
	opt->precision = 0xffffffffffffffff;
	opt->lmod = 0;
	opt->cnvrtsp = '\0';
	return (opt);
}

t_printops	*readops(char **start)
{
	int			i;
	t_printops	*opt;
	int			ret;

	if ((opt = initoption()) == NULL)
		return (NULL);
	i = 1;
	while (*(*start + i) != '\0' && (ret = is_cnvrtsp(*(*start + i))) == 0)
	{
		storeops(start, i, opt);
		if ((*(*start + i) <= '9' && *(*start + i) >= '1')
				|| *(*start + i) == '.')
		{
			if (*(*start + i) == '.')
				i++;
			while (*(*start + i) <= '9' && *(*start + i) >= '0')
				i++;
		}
		else
			i++;
	}
	adjust_ops(opt, *start + i, ret, start);
	return (opt);
}

void		adjust_ops(t_printops *opt, char *i, int ret, char **start)
{
	char	sp;
	size_t	precision;

	opt->cnvrtsp = *i;
	if (ret == -1)
		opt->cnvrtsp = '\0';
	if (*i == '\0' || ret == -1)
		i--;
	*start = i + 1;
	precision = opt->precision;
	sp = opt->cnvrtsp;
	if (precision != 0xffffffffffffffff && (opt->flag).min_0 == '0'
	&& (sp == 'd' || sp == 'i' || sp == 'o'
		|| sp == 'u' || sp == 'x' || sp == 'X'))
		(opt->flag).min_0 = '\0';
}

void		storeops(char **start, int i, t_printops *opt)
{
	opt->flag.sharp = (*(*start + i) == '#') ? '#' : opt->flag.sharp;
	if ((*(*start + i) == '0' && opt->flag.min_0 != '-')
			|| *(*start + i) == '-')
		opt->flag.min_0 = *(*start + i);
	if ((*(*start + i) == ' ' && opt->flag.plus_sp != '+')
			|| *(*start + i) == '+')
		opt->flag.plus_sp = *(*start + i);
	if (*(*start + i) <= '9' && *(*start + i) > '0' && opt->width == 0)
		opt->width = ft_atozu(*start + i);
	if (*(*start + i) == '.')
		opt->precision = ft_atozu(*start + ++i);
	if (*(*start + i) == 'l' && opt->lmod == none)
		opt->lmod = l;
	else if (*(*start + i) == 'l' && opt->lmod != none)
		opt->lmod = ll;
	if (*(*start + i) == 'h' && opt->lmod == none)
		opt->lmod = h;
	else if (*(*start + i) == 'h' && opt->lmod != none)
		opt->lmod = hh;
	if (*(*start + i) == 'L')
		opt->lmod = L;
	if (*(*start + i) == 'j')
		opt->lmod = j;
}
