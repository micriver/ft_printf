/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 15:38:54 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/31 15:02:27 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	p_conv(va_list args)
{
	char *res;
	void *ptr;

	ptr = va_arg(args, void *);
	res = ft_llitoa_base((long)ptr, NULL, 16, 0);
	res = ft_strjoin("0x", res);
	if (arg.width || CHECK_BIT(arg.flgmods, MINUS_F))
		p_form(res);
	else
		prfree(res);
}
