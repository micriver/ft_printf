/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:50:30 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/31 14:10:22 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

/*
** prfree prints the final converted argument string,
** adds its # of chars to the char_count, 
** and resets the struct for the next argument
*/

void		prfree(char *res)
{
	arg.char_count += ft_intputstr(res);
	free(res);
	reset_struct();
}

/*
** roundup() and decconv() are both supporting the f_conv
*/

char			*roundup(char *str)
{
	int		i;
	char	number;

	if (arg.precision == 0 || (CHECK_BIT(arg.flgmods, LNG_D)))
	{
		arg.precision = 6;
		i = arg.precision;
	}
	else if (CHECK_BIT(arg.flgmods, LONEDEC) || arg.precision == 0)
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
	if ((CHECK_BIT(arg.flgmods, LNG_D)) \
			|| (CHECK_BIT(arg.flgmods, LONGINT)))
		str[i - 1] = number + 1;
	return (str);
}

long double		decconv(long double dec)
{
	int i;

	i = 0;
	if (dec < 0)
		dec *= -1;
	if ((arg.precision == 0) && ((CHECK_BIT(arg.flgmods, LNG_D)) \
			|| (CHECK_BIT(arg.flgmods, LONGINT))))
		arg.precision = 6;
	if ((arg.precision == 0) && (!(CHECK_BIT(arg.flgmods, LNG_D)) \
			|| !(CHECK_BIT(arg.flgmods, LONGINT))))
	{
		while (i++ < 3)
			dec = dec * 10;
	}
	else if (arg.precision)
	{
		while (i++ < arg.precision)
			dec = dec * 10;
	}
	return (dec);
}