/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:15:22 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/31 16:04:59 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*u_return_value(va_list args)
{
	uint64_t u;
	char *result;

	u = 0;
	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_uitoa(va_arg(args, unsigned short int));
	//else if (CHECK_BIT(arg.flgmods, LONGINT))
	//	result = ft_uitoa((unsigned long int)va_arg(args, uint64_t));
	//else
	//	result = ft_uitoa((unsigned int)va_arg(args, int));
	else
		result = NULL;
	return (result);
}

//uint64_t u_return_value(va_list args)
//{
//	uint64_t u;
//
//	u = 0;
//	if (CHECK_BIT(arg.flgmods, SHOINT))
//		u = ((unsigned short int)va_arg(args, unsigned int));
//	else if (CHECK_BIT(arg.flgmods, LONGINT))
//		u = ((unsigned long int)va_arg(args, uint64_t));
////	else if (CHECK_BIT(arg.flgmods, LNGLNG))
////		u = (va_arg(args, unsigned long long int));
//	else
//		u = ((unsigned int)va_arg(args, int));
//	return (u);
//}

char *ull_ret_val(va_list args)
{
	char *result;

	return (result = ft_ull_itoa(va_arg(args, unsigned long long int)));
}
