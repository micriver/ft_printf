/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:15:22 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/08 18:27:45 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	u_ret_val(va_list args)
{
	char *result;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_uitoa(va_arg(args, uint64_t));
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		result = ft_uitoa(va_arg(args, uint64_t));
	else
		result = ft_uitoa(va_arg(args, uint64_t));
	dui_print(result);
}

void	ull_ret_val(va_list args)
{
	//char *result;

	dui_print(ft_ull_itoa(va_arg(args, unsigned long long int)));
}
