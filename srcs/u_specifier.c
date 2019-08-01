/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:15:22 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/31 18:28:31 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*u_return_value(va_list args)
{
	char *result;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_uitoa(va_arg(args, uint64_t));
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		result = ft_uitoa(va_arg(args, uint64_t));
	else
		result = ft_uitoa(va_arg(args, uint64_t));
	return (result);
}

char *ull_ret_val(va_list args)
{
	char *result;

	return (result = ft_ull_itoa(va_arg(args, unsigned long long int)));
}
