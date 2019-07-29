/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/29 15:09:35 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*u_specifier(int64_t u)
{
	char *result;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_itoa(u);
	//else if (CHECK_BIT(arg.flgmods, LONGINT))
	//	result = ft_itoa((long int)va_arg(args, int64_t));
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		result = ft_long_itoa(u);
	else
		result = NULL;
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
		result = NULL;
	return (result);
}

