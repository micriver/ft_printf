/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/29 15:49:33 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

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

char	*di_specifier(int64_t di)
{
	char *result;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_itoa(di);
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		result = ft_itoa(di);
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		result = ft_long_itoa(di);
	else
		result = NULL;
	return (result);
}

