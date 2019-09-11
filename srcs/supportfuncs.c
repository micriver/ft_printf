/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportfuncs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 10:50:30 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 16:22:11 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

/*
** prfree prints the final converted argument string,
** adds its # of chars to the char_count,
** and resets the struct for the next argument
*/

void			prfree(char *res)
{
	if (arg.fd)
	{
		ft_intputstr_fd(res, arg.fd);
		arg.char_count += ft_strlen(res);
		reset_struct();
	}
	else
	{
		arg.char_count += ft_intputstr(res);
		reset_struct();
	}
	free(res);
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

/*
** The following functions are 'o' flag checks being called
** in the formatting function for 'o'. They handle various
** flag edge cases.
*/

char			*o_explicitzero(char *temp, char *origstr)
{
	if (ft_strcmp(origstr, "0") == 0)
		temp[0] = '\0';
	else
		temp = ft_strcpy(temp, origstr);
	return (temp);
}

/*
** The function below supports the width building functions
** in the 's' formatting file
*/

void			s_widthhandle(char *temp, char *origstr)
{
	char *temp2;

	if (PREC)
	{
		temp2 = s_wbuild(temp, origstr);
		prfree(temp2);
	}
	else
	{
		temp = ft_strdup(origstr);
		temp2 = s_wbuild(temp, origstr);
		prfree(temp2);
	}
}
