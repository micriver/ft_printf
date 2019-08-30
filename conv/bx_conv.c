/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bx_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/24 19:50:07 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/29 22:56:03 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	bx_conv(va_list args)
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
		arg.char_count += ft_intputstr(res);
		reset_struct();
		free(res);
	}
	else
	{
		res = ft_itoa_baseUP(n, res, 16, 0);
		arg.char_count += ft_intputstr(res);
		reset_struct();
		free(res);
	}
}
