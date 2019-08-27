/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:21:37 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/27 13:45:22 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

void	f_conversion(long double num)
{
	int	ipart;
	long double fpart;
	char *whlnum;
	char *decnum;
	int i;
	int fakeprec;

	i = 0;
	fakeprec = 6;
	ipart = (int)num;
	whlnum = ft_itoa(ipart);
	fpart = num - ipart;	
	//if (fpart < 0)
	//	fpart *= -1;
	//while (i < fakeprec)
	//{
	//	fpart = fpart * 10;
	//	i++;
	//}
	ipart = (int)fpart;
	decnum = ft_itoa(ipart);



	//printf("%s\n", whlnum);
	//printf("%.10Lf\n", fpart);
	//printf("Your decimal count for fpart = %d\n", count);
	//printf("Your converted to whole number fpart = %Lf\n", fpart);
	//printf("your decimals as an int = %d\n", ipart);
	printf("Your whole number as a string = %s\n", whlnum);
	//printf("Your decimal number as a string = %s\n", decnum);
	printf("Your decimal number as a string = %s\n", decnum);
	printf("\n");
	ft_putstr(whlnum);
	ft_putchar('.');
	ft_putstr(decnum);
}

int		main()
{
	//float value = -37.66666;
	//float value = -10.000;
	//float value = -23.688;
	//float value = -11029.000568;
	//float value = -11029.8641;
	float value = -12229.12436800;
	printf("Prior to f_conv, your float value = %.10f\n", value);
	f_conversion(value);
}
