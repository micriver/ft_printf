/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:45:33 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 19:10:54 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	xX_conv(va_list args)
{
	char	*res;
	int64_t	n;
	char	*temp;

	n = va_arg(args, int64_t);
	res = NULL;
	if (n == 0)
	{
		temp = "0";
		res = ft_strnew(1);
		res = ft_strcpy(res, temp);
		xX_form(res);
	}
	else if (arg.conv == 'X')
	{
		res = ft_itoa_baseUP(n, res, 16, 0);
		xX_form(res);
	}
	else
	{
		res = ft_itoa_base(n, res, 16, 0);
		xX_form(res);
	}
}
