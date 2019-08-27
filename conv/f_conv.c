/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:21:37 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/27 15:16:55 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

//create ft_power(int base, int exponent)
//		 ft_power(10, arg.precision);
//fpart = round(double value);
//		0.45 / (10 to the precision(th) power)

long double		decconv(long double dec)
{
	int i;

	i = 0;
	if (dec < 0)
		dec *= -1;
	while (i++ < arg.precision)
		dec = dec * 10;
	return (dec);
}



void	f_conv(va_list args)
{
	//If the precision is missing, it is taken as 6
	if (!arg.precision && arg.precision != 0)
		arg.precision = 6;
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
	//function to round the decimals
	//should go here prior to itoa
	fpart = decconv(fpart);
	ipart = (int)fpart;
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
	//if the precision is explicitly zero...
	if (arg.precision == 0)
	{
		free(whlnum);
		free(decnum);
	}
	else
	{
		ft_putchar('.');
		ft_putstr(decnum);
		free(whlnum);
		free(decnum);
	}
}
