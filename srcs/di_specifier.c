/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/31 19:47:43 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//on the dui branch now!

#include "../headers/ft_printf.h"

//int64_t		di_return_value(va_list args)
//{
//	int64_t di;
//
//	di = 0;
//	if (CHECK_BIT(arg.flgmods, SHOINT))
//		di = ((short int)va_arg(args, int));
//	else if (CHECK_BIT(arg.flgmods, LONGINT))
//		di = ((long int)va_arg(args, int));
//	else if (CHECK_BIT(arg.flgmods, LNGLNG))
//		di = (va_arg(args, long long int));
//	else
//		di = (va_arg(args, int));
//	return (di);
//}

char	*di_ret_val(va_list args)
{
	//int64_t di;
	char *result;

	//di = 0;
	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_itoa(va_arg(args, int));
	//else if (CHECK_BIT(arg.flgmods, LONGINT))
	//	di = ((long int)va_arg(args, int));
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		result = ft_long_itoa(va_arg(args, long long int));
		//result = (va_arg(args, long long int));
	else
		result = ft_itoa(va_arg(args, int));
	return (result);
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
		result = ft_itoa(di);
		//result = NULL;
	return (result);
}

