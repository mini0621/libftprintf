/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 17:08:51 by mnishimo          #+#    #+#             */
/*   Updated: 2018/12/18 15:12:18 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

int main(int argc, char **argv)
{
	int ret;

	printf("real#: %#1x\n", 56);
	printf("real0: %01x\n", 56);
	printf("real-: %-1p\n", "aaaaaaaaaa");
	printf("real+: %+10i\n", 56);
	printf("real : % 10i\n", 56);
	/*printf("real#0: %#0i\n", 56);
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
	//ret = ft_printf("ft: %caaa\n");
	//printf("returned : %i\n", ret);
	return (0);
}
