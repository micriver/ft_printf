/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:53:17 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 13:03:41 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		cast(va_list args, long long int *n)
{
	if (CHECK_BIT(arg.flgmods, LONGINT))
		(*n) = va_arg(args, long int);
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		(*n) = va_arg(args, long long int);
	else if (arg.conv == 'u')
		(*n) = va_arg(args, unsigned long long int);
	else
		(*n) = va_arg(args, int);
}

void		dui_conv(va_list args)
{
	char			*res;
	long long int	n;

	cast(args, &n);
	if (arg.conv == 'd' || arg.conv == 'i')
		res = ft_llitoa(n);
	else
		res = ft_ullitoa(n);
	dui_form(res);
}
