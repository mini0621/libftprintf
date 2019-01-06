/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 18:57:02 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/05 22:26:20 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int is_cnvrtsp(char c)
{
	if (c == 'i' || c == 'd' || c == 'o' || c == 'u' || c == 'x' || c == 'X'
		|| c == 'c' || c == 'f' || c == 's' || c == 'p' || c == 'e' || c == 'g'
		|| c == '%')
		return (1);
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
	opt->width = -1;
	opt->precision = -1;
	opt->lmod = 0;
	opt->cnvrtsp = '\0';
	return (opt);
}

t_printops	*readops(char **start)
{
	int	i;
	t_printops	*opt;

	if ((opt = initoption()) == NULL)
		return (NULL);
	i = 1;
	while (*(*start + i) != '\0' && is_cnvrtsp(*(*start + i)) == 0)
	{
//		printf("hello :: *(*start + i) = %ccheck : %c\n", *(*start + i), opt->flag.sharp);
		storeops(start, i, opt);
		if (*(*start + i) <= '9' && *(*start + i) >= '1')
		{
			while (*(*start + i) <= '9' && *(*start + i) >= '0')
				i++;
		}
		else
			i++;
		}
	opt->cnvrtsp = *(*start + i);
	if (opt->precision == -1 && opt->cnvrtsp == 'f')
		opt->precision = 6;
	*start = *start + i + 1;
	return (opt);
}

void		storeops(char **start, int i, t_printops *opt)
{
		opt->flag.sharp = (*(*start + i) == '#') ? '#': opt->flag.sharp;
		if ((*(*start + i) == '0' && opt->flag.min_0 != '-')
				|| *(*start + i) == '-')
			opt->flag.min_0 = *(*start + i);
		if ((*(*start + i) == ' ' && opt->flag.plus_sp != '+')
				|| *(*start + i) == '+')
			opt->flag.plus_sp = *(*start + i); 
		if (*(*start + i) <= '9' && *(*start + i) > '0' && opt->width == -1)
			opt->width = ft_atoi(*start + i);
		if (*(*start + i) == '.')
			opt->precision = ft_atoi(*start + ++i);
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
}
