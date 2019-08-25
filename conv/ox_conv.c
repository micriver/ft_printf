/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ox_conv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:08:58 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/24 19:25:54 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	ox_conv(va_list args)
{
	char	*res;
	int		n;
	char	*temp;

	n = va_arg(args, int64_t);
	res = NULL;
	if (n == 0)
	{
		temp = "0";
		res = ft_strnew(1);
		res = ft_strcpy(res, temp);
	}
	else if (arg.conv == 'o')
		res = ft_itoa_base(n, res, 8, 0);
	else
		res = ft_itoa_base(n, res, 16, 0);
	arg.char_count += ft_intputstr(res);
	reset_flags();
	free(res);
}
