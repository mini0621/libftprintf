/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   castingtest.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 21:45:40 by mnishimo          #+#    #+#             */
/*   Updated: 2019/01/06 13:26:58 by mnishimo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>


int main()
{
	int i;
	unsigned short s;
	unsigned char c;
	unsigned long long ll;
	unsigned long l;



	i = -10;
	s = (unsigned short)i;

	c = (unsigned char)i;
	ll = (unsigned long long)i;
	l = (unsigned long)i;

	printf("so i = %i, s = %hi, c = %hhi, ll = %lli, l = %li\n", i, s, c, ll, l);
	ll = (unsigned long long)s;
	printf("so i = %i, s = %hi, c = %hhi, ll = %lli, l = %li\n", i, s, c, ll, l);
	ll = (unsigned long long)c;
	printf("so i = %i, s = %hi, c = %hhi, ll = %lli, l = %li\n", i, s, c, ll, l);
	ll = (unsigned long long)l;
	printf("so i = %i, s = %hi, c = %hhi, ll = %lli, l = %li\n", i, s, c, ll, l);
	return (0);
}
