/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:08:51 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/17 00:34:06 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>
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


	double a = 0.1433870e+308;
	double b = 0.101;
	//ft_printf("%lu\n", -42);
	//printf("%lu\n", -42);
	//printf("%.1000f\n", a);
	printf("%.0p, %.p\n", 0, 0);
	ft_printf("%.0p, %.p\n", 0, 0);
	//ft_dprintf(-1, "%18446744073709551615d\n", 1);
	printf("%*d\n", "ll", 11);
	printf("%lld\n",  11);
	printf("%9.10lld\n", 11);
	return (0);
}
