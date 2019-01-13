/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_e.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/19 18:00:27 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/13 18:59:58 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*prcs_e(va_list *ap, t_printops *opt, size_t *l)
{
	char		*ret;
	t_lm		lm;
	int			sign;
	
	lm = opt->lmod;
	ret = NULL;
	if (lm == 5)
		ret = prcs_eld(ap, opt, &sign);
	else
		ret = prcs_edb(ap, opt, &sign);
	ret = prcs_flags(opt, &ret, sign);
	if (ret == NULL)
		return (NULL);
	*l = ft_strlen(ret);
	return (ret);
}


char	*normalize(char **s, int expo, size_t precision,  int iszero)
{
	char	*a;
	char	*b;

	if (expo < 0)
		expo--;
	round_e(s, precision);
	if (s == NULL || *s == NULL) 
		return (NULL);
	if (iszero == 1)
	{

		a = ft_strnew(precision + 5);
		ft_strcpy(a, "0.");
		ft_memset(a + 2, '0', precision);
		ft_strcat(a, "+00");
		return (a);
	}	
	b = ft_itoa(expo);
	a = ft_strnew(precision + 4);
	ft_strncpy(a, *s, 1);
	a[1] = '.';
	ft_strncpy(a + 2, *s + 1, precision);
	a[precision + 2] = 'e';
	if (expo > 0)
		a[precision + 3] = '+';
	a = ft_strjoinfree(&a, &b, 3);
	free(*s);
	return (a);
}

char	*prcs_edb(va_list *ap, t_printops *opt, int *sign)
{
	double		arg;
	t_double	*n;
	char		*ret;
	char		*s;

	arg = va_arg(*ap, double);
	if ((n = get_double(arg)) == NULL)
		return (NULL);
	*sign = (arg == 0) ?  0:n->sign;
	if (n->expo == 1024)
		ret = sp_double(n->sign ,n->frac);
	else if (arg != 0)
		ret = ft_dbtoa(n, opt->precision, 1);
	else
		return (normalize(NULL, 0, 0, 1));
	ret = normalize(&ret, get10th_expo(n->expo), opt->precision, 0);
	if (*sign < 0)
	{
		s = ft_strdup("-");
		ret = ft_strjoinfree(&s, &ret, 3);
	}
	free(n);
	return(ret);
}

char	*prcs_eld(va_list *ap, t_printops *opt, int *sign)
{
	long double	arg;
	t_double	*n;
	char		*s;
	char		*ret;

	arg = va_arg(*ap, long double);
	if ((n = get_ldouble(arg)) == NULL)
		return (NULL);
	*sign = (arg == 0) ? 0:n->sign;
	if (n->expo == 0xefff)
		ret = sp_double(n->sign ,n->frac);
	else if (arg != 0)
		ret = ft_ldtoa(n, opt->precision, 1);
	else
		return (normalize(NULL, 0, 0, 1));
	ret = normalize(&ret, get10th_expo(n->expo), opt->precision, 0);
	if (*sign < 0)
	{
		s = ft_strdup("-");
		ret = ft_strjoinfree(&s, &ret, 3);
	}
	free(n);
	return (ret);
}

void	round_e(char **s, size_t precision)
{
	char	*ret;

	if (round_s(s, 0, precision) == 1)
	{
		ret = ft_strdup("1");
		*s = ft_strjoinfree(&ret, s, 3);
	}
}
