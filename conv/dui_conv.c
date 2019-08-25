/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_conv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 13:53:17 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/24 19:19:39 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	dui_conv(va_list args)
{
	char *res;

	if (arg.conv == 'd' || arg.conv == 'i')
		res = ft_llitoa(va_arg(args, int));
	else
		res = ft_ullitoa(va_arg(args, unsigned long long int));
	arg.char_count += ft_intputstr(res);
	reset_flags();
	free(res);
}
