/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:15:22 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/29 19:48:18 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdint.h>

int64_t		u_return_value(va_list args)
{
	int64_t u;

	u = 0;
	if (CHECK_BIT(arg.flgmods, SHOINT))
		u = ((unsigned short int)va_arg(args, uint64_t));
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		u = ((unsigned long int)va_arg(args, uint64_t));
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		u = ((unsigned long long int)va_arg(args, uint64_t));
	else
		u = ((unsigned int)va_arg(args, int));
	return (u);
}

char	*u_specifier(int64_t u)
{
	char *result;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_itoa(u);
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		result = ft_itoa(u);
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		result = ft_long_itoa(u);
	else
		result = NULL;
	return (result);
}

