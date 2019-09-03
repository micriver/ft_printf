/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:48:31 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 21:27:51 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	o_conv(va_list args)
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
		o_form(res);
	}
	else if (arg.conv == 'o')
	{
		res = ft_itoa_base(n, res, 8, 0);
		o_form(res);
	}
}
