/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:48:31 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/04 14:34:32 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

uint64_t		o_cast(va_list args, uint64_t n)
{
	if (CHECK_BIT(arg.flgmods, LNGLNG) || CHECK_BIT(arg.flgmods, LONGINT))
		n = va_arg(args, unsigned long long int);
	else
		n = va_arg(args, unsigned int);
	return (n);
}

void			o_conv(va_list args)
{
	char		*res;
	uint64_t	n;
	char		*temp;

	n = o_cast(args, 0);
	res = NULL;
	if (n == 0)
	{
		temp = "0";
		res = ft_strnew(1);
		res = ft_strcpy(res, temp);
		o_form(res);
	}
	else if (arg.conv == 'o')
	{
		res = ft_uitoa_base(n, res, 8, 0);
		o_form(res);
	}
}
