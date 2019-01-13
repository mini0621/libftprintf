/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:08:51 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/13 20:37:56 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	int ret;
	//t_printops *opt = readops(&(argv[1]));
//	printf("flags : charp %c, min0 %c, +sp %c \n width : %i, precision : %i, lmod: %i, cmvrtsp: %c \n",opt->flag.sharp, opt->flag.min_0, opt->flag.plus_sp, opt->width, opt->precision, opt->lmod, opt->cnvrtsp);
//	free(opt);
//	ret = printf("real#: %Li\n", 5);
/*	printf("real0: %01x\n", 56);
	printf("real-: %-1p\n", "aaaaaaaaaa");
	printf("real+: %+10i\n", 56);
	printf("real : % 10i\n", 56);
*/	/*printf("real#0: %#0i\n", 56);
	printf("real: %#-i\n", 56);
	printf("real: %#+i\n", 56);
	printf("real: %0-i\n", 56);
	printf("real: %0+i\n", 56);
	printf("real: %0 i\n", 56);
	printf("real: %-+i\n", 56);
	printf("real: %+ i\n", 56);
	printf("real: %#0-i\n", 56);
	printf("real: %#0+i\n", 56);
	printf("real: %#0 i\n", 56);
	printf("real: %0-+i\n", 56);
	printf("real: %0- i\n", 56);
	printf("real: %-+ i\n", 56);
	printf("real: %#0-+i\n", 56);
	printf("real: %#0- i\n", 56);
	printf("real: %0-+ i\n", 56);
	printf("real: %#0-+ i\n", 56);
*/
/*
//ret = ft_printf("ft: %.100Lf\n", 1.23L);
ft_printf("fto: %10oa\n", 10);
ft_printf("ftx: %10xa\n", 10);
ft_printf("ftd: %10da\n", 10);
ft_printf("ftu: %10ua\n", 10);
ft_printf("ftX: %10Xa\n", 10);
ft_printf("ftf: %%a\n", 10.0);


printf("ft: %.50sa\n", "Hellooooooooo");
printf("ft: %10ca\n", 'Y');
printf("ft: %-10da\n", 10);
printf("ft: %-10ua\n", 10);
printf("ft: %.100Lf\n", 1.4e+10L);
printf("ft: %.100Lf\n", );
*/
//	printf("returned : %i\n", ret);

	
long double a = -1.933870e+37L;
double b = 0.101;
//printf("real1 is %Le\n");	
ft_printf("%c is a string", '\0');
printf("%10c is a string", '\0');


	return (0);
}
