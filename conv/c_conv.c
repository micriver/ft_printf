/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:52:23 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/10 11:58:55 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	c_conv(va_list args)
{
	char res;
	char *widthres;

	res = (signed char)va_arg(args, int);
	if (arg.width)
	{
		widthres = c_form(res);
		arg.char_count += ft_intputstr(widthres);
		free(widthres);
		reset_struct();
	}
	else
	{
		arg.char_count += ft_intputchar(res);
		reset_struct();
	}
}
