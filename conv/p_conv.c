/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:38:54 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/24 19:21:06 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	p_conv(va_list args)
{
	char *res;
	void *ptr;

	res = NULL;
	ptr = va_arg(args, void *);
	res = ft_llitoa_base((long)ptr, res, 16, 0);
	res = ft_strjoin("0x", res);
	arg.char_count += ft_intputstr(res);
	reset_flags();
	free(res);
}
