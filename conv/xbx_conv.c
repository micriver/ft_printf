/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xbx_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:43:24 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 13:09:59 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	xbx_conv(va_list args)
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
		xbx_form(res);
	}
	else if (arg.conv == 'X')
	{
		temp = ft_itoa_base_up(n, res, 16, 0);
		xbx_form(temp);
		free(res);
	}
	else
	{
		temp = ft_itoa_base(n, 16, 0);
		xbx_form(temp);
	}
}
