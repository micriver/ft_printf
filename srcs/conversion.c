/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/29 15:08:56 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>
#include <time.h>


int64_t		u_return_value(va_list args)
{
	int64_t u;

	u = 0;
	if (CHECK_BIT(arg.flgmods, SHOINT))
		u = ((unsigned short int)va_arg(args, int64_t));
	//else if (CHECK_BIT(arg.flgmods, LONGINT))
	//	u = ((long int)va_arg(args, int64_t));
	//else if (CHECK_BIT(arg.flgmods, LNGLNG))
	//	u = ((long long)va_arg(args, int64_t));
	else
		u = (va_arg(args, int));
	return (u);
}

int64_t		di_return_value(va_list args)
{
	int64_t di;

	di = 0;
	if (CHECK_BIT(arg.flgmods, SHOINT))
		di = ((short int)va_arg(args, int64_t));
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		di = ((long int)va_arg(args, int64_t));
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		di = ((long long)va_arg(args, int64_t));
	else
		di = (va_arg(args, int));
	return (di);
}

char	*conversion(int *i, char *str, va_list args)
{
	char *result;
	//int64_t di;

	master_pars(str, i);
	//majority of the work has to happen below here now
	//typecast for each length modifier happens in the actual conversion
	//specifier function/c file
	//place a while loop here where you loop through n
	//and a list of specifiers in a string
	if (str[*i] == 'd' || str[*i] == 'i' )
	{
		int64_t di; //this needs to be able to hold at least 64 bits
					//for whatever value comes back from di_return value
		di = di_return_value(args);
		result = di_specifier(di);
	}
	if (str[*i] == 'u')
	{
		int64_t u;
		u = u_return_value(args);
		result = u_specifier(u);
	}
	else if (str[*i] == 's')
		result = s_specifier(args);
	else
		result = NULL; 
	return (result);
}

