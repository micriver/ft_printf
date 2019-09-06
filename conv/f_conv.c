/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:21:37 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/05 18:41:21 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void			lonedec(char *whlnum, char *decnum)
{
	char	number;

	if (ft_strcmp(whlnum, "0") == 0)
	{
		ft_putstr(whlnum);
		ft_putchar('.');
		while (arg.precision-- > 0)
			ft_putchar('0');
	}
	else
	{
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

void			preczero(char *whlnum, char *decnum)
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

void			precpresent(char *whlnum, char *decnum)
{
	ft_putstr(whlnum);
	ft_putchar('.');
	ft_putstr(decnum);
}

void			f_conv(va_list args)
{
	long double		num;
	long long int	ipart;
	double			fpart;
	char			*whlnum;
	char			*decnum;

	num = va_arg(args, double);
	(void)args;
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
	reset_struct();
}
