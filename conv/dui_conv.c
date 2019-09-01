/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:53:17 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/01 15:44:58 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int64_t		cast(va_list args, int64_t n)
{
	if (CHECK_BIT(arg.flgmods, LNGLNG))
		n = va_arg(args, long long int);
	else if (arg.conv == 'u')
		n = va_arg(args, unsigned long long int);
	else
		n = va_arg(args, int);
	return (n);
}

void	dui_conv(va_list args)
{
	char *res;
	int64_t n;

	n = cast(args, 0);
	if (arg.conv == 'd' || arg.conv == 'i')
		res = ft_llitoa(n);
	else
		res = ft_ullitoa(n);
	arg.char_count += ft_intputstr(res);
	reset_struct();
	free(res);
}
