/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/23 20:03:06 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>
#include <time.h>

int64_t		di_return_value(va_list args)
{
	int64_t di;

	di = 0;
	if (CHECK_BIT(arg.flgmods, SHOINT))
		di = ((short int)va_arg(args, int64_t));
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		di = ((long int)va_arg(args, int64_t));
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		di = ((long long int)va_arg(args, int64_t));
	else
		di = (va_arg(args, int64_t));
	return (di);
}

char	*conversion(int *i, char *str, va_list args)
{
	char *result;
	int64_t di;

	master_pars(str, i);
	//majority of the work has to happen below here now
	//typecast for each length modifier happens in the actual conversion
	//specifier function/c file
	//place a while loop here where you loop through n
	//and a list of specifiers in a string
	if (str[*i] == 'd' || str[*i] == 'i')
	{
		di = di_return_value(args);
		result = di_specifier(di);
	}
	else if (str[*i] == 's')
		result = s_specifier(args);
	else
		result = NULL; 
	return (result);
}

