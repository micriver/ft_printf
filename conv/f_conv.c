/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:21:37 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/27 14:43:07 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

long double		deccount(long double dec)
{
	int i;
	int fakeprec;

	i = 0;
	fakeprec = 6;
	if (dec < 0)
		dec *= -1;
	while (i++ < fakeprec)
		dec = dec * 10;
	return (dec);
}



void	f_conv(va_list args)
{
	//(void)args;
	//ft_putstr("here");
	double num;
	num = va_arg(args, double);
	int	ipart;
	long double fpart;
	char *whlnum;
	char *decnum;

	ipart = (int)num;
	whlnum = ft_itoa(ipart);
	fpart = num - ipart;	
	fpart = deccount(fpart);
	ipart = (int)fpart;
	//function to round the decimals
	//should go here prior to itoa
	decnum = ft_itoa(ipart);



	//printf("%s\n", whlnum);
	//printf("%.10Lf\n", fpart);
	//printf("Your decimal count for fpart = %d\n", count);
	//printf("Your converted to whole number fpart = %Lf\n", fpart);
	//printf("your decimals as an int = %d\n", ipart);
	//printf("Your whole number as a string = %s\n", whlnum);
	//printf("Your decimal number as a string = %s\n", decnum);
	//printf("Your decimal number as a string = %s\n", decnum);
	//printf("\n");
	ft_putstr(whlnum);
	ft_putchar('.');
	ft_putstr(decnum);
	free(whlnum);
	free(decnum);
}
