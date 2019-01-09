/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 13:27:07 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/09 12:20:32 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <math.h>
#include <stdio.h>
#include "libft/libft.h"

int main()
{
	long double a;

	a = 0.1;
		//3.64519953188247460253E-4951L;
	short c;
	int expo;
	uint64_t frac;


	int count = 52;
	while (frac % 2 == 1)
	{
		count--;
		frac = frac >> 1;
	}
	printf("count : %i", count);
	printf("frac is ...%lld\n", frac);
	printf("");

	ft_memcpy(&c, &a, 2);
	printf("%x\n",c);
	return (0);
}
