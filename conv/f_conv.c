/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:21:37 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/28 16:59:41 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

//unsigned long long	ft_power(int base, unsigned int exponent)
//{
//	unsigned long long result;
//
//	result = 1;
//	if (exponent == 0)
//		return (1);
//	while (exponent != 0)
//	{
//		result *= base;
//		--exponent;
//	}
//	return (result);
//}

//double		round(double value)
//{
//	double magic;
//	
//	//instead of .45, the rounded values
//	//matched with regular printf
//	//when it was changed to 0.25
//	magic = 0.25;
//	if (arg.precision != 0)
//	{
//		magic /= (ft_power(10, arg.precision));
//		return (value += magic);
//	}
//	else
//		return (value += magic);
//}

char	*roundup(char *str)
{
	int i;
	char number;

	i = arg.precision;
	number = str[i - 1];
	if (number > '5' && number != '9')
		str[i - 1] = number + 1;
	if (number == '9')
	{
		str[i - 1] = '0';
		str[i - 2] = '1';
	}
	return (str);
}

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
	//if there is no precision, it starts @-1
	//if (arg.precision < 0)
	//	arg.precision = 6;
	double num;
	num = va_arg(args, double);
	long long int	ipart;
	long double fpart;
	char *whlnum;
	char *decnum;

	decnum = NULL;
	ipart = (int)num;
	whlnum = ft_llitoa(ipart);
	//if just a decimal point appears
	if (CHECK_BIT(arg.flgmods, LONEDEC || arg.precision == 0))
	{
		ft_putstr(whlnum);
		free(whlnum);
	}
	//if there is a precision
	else
	{
		fpart = num - ipart;	
		fpart = decconv(fpart);
		ipart = (unsigned long long int)fpart;
		decnum = ft_ullitoa(ipart);
		decnum = roundup(decnum);
		ft_putstr(whlnum);
		ft_putchar('.');
		ft_putstr(decnum);
		free(whlnum);
		free(decnum);
	}
	//else
	//{
	//	//if the precision is explicitly zero...
	//	if (arg.precision == 0 || ))
	//	{
	//		free(whlnum);
	//		free(decnum);
	//	}
	//	else
	//	{
	//		ft_putchar('.');
	//		ft_putstr(decnum);
	//		free(whlnum);
	//		free(decnum);
	//	}
}
