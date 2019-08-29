/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:21:37 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/29 10:14:47 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*roundup(char *str)
{
	int i;
	char number;

	if (CHECK_BIT(arg.flgmods, LONEDEC) || arg.precision == 0)
		i = 3;
	else
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
	if (arg.precision == 0)
	{
		while (i++ < 3)
			dec = dec * 10;
	}
	else
	{
		while (i++ < arg.precision)
			dec = dec * 10;
	}
	return (dec);
}

void	lonedec(char *whlnum, char *decnum)
{
	if (ft_strcmp(whlnum, "0") == 0)
	{
		ft_putstr(whlnum);
		ft_putchar('.');
		while (arg.precision-- > 0)
			ft_putchar('0');
	}
	else
	{
		char number;

		number = whlnum[ft_strlen(whlnum) - 1];
		if (decnum[0] >= '5' && number != 9)
			whlnum[ft_strlen(whlnum) - 1] = number + 1;
		if (decnum[0] >= '5' && number == '9')
		{
			whlnum[ft_strlen(whlnum) - 1] = '0';
			whlnum[ft_strlen(whlnum) - 2] = '1';
		}
		ft_putstr(whlnum);
	}
}

void	preczero(char *whlnum, char *decnum)
{
	char number;

	number = whlnum[ft_strlen(whlnum) - 1];
	if (decnum[0] >= '5' && number != 9)
		whlnum[ft_strlen(whlnum) - 1] = number + 1;
	if (decnum[0] >= '5' && number == '9')
	{
		whlnum[ft_strlen(whlnum) - 1] = '0';
		whlnum[ft_strlen(whlnum) - 2] = '1';
	}
	ft_putstr(whlnum);
}

void	precpresent(char *whlnum, char *decnum)
{
		ft_putstr(whlnum);
		ft_putchar('.');
		ft_putstr(decnum);
}

void	f_conv(va_list args)
{
	long double num;
	long long int ipart;
	double fpart;
	char *whlnum;
	char *decnum;

	num = va_arg(args, double);
	decnum = NULL;
	ipart = (int)num;
	whlnum = ft_llitoa(ipart);
	fpart = num - ipart;	
	fpart = decconv(fpart);
	ipart = (long long int)fpart;
	decnum = ft_llitoa(ipart);
	decnum = roundup(decnum);
	if (CHECK_BIT(arg.flgmods, LONEDEC))
		lonedec(whlnum, decnum);
	else if (arg.precision == 0)
		preczero(whlnum, decnum);
	else if (arg.precision > 0)
		precpresent(whlnum, decnum);
	free(whlnum);
	free(decnum);
}
