/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dbtoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:21:57 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/13 01:25:48 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_dbtoa(t_double *n, int precision, int e)
{
	char	*ret;
	char	*integer;
	int		p;
	int		subnormal;

	subnormal = ((short)n->expo == -1023) ? 1: 0;
	if ((ret = get_frac10(n, 52, subnormal)) == NULL)
		return (NULL);
	//printf("check :%s\n", ret);
	p = get10th_expo(n->expo) + 1;
	if (e == 1)
		return (ft_strsubfree(ret, skip_zeros(ret), precision + 2));
	ret = ft_strsubfree(ret, skip_zeros(ret), p + precision + 1);
//	printf("check2 :%s\n", ret);
//	printf("p : %i\n", p);
	integer = sub_integer(&ret, p, precision);
	if (precision == 0)
		return (integer);
//	printf("check3 :%s\n", ret);	
	ret = ft_strsubfree(ret, 0, precision);
	if (ft_strlen(ret) < precision)
		ret = prcs_precision_end('d', &ret, precision);
//	printf("check5 ret:%s\ncheck5 int:%s\n", ret, integer);
	ret = ft_strjoinfree(&integer, &ret, 3);
	return (ret);
}
