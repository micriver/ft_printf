/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:52:23 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/29 22:57:45 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	c_conv(va_list args)
{
	char res;

	res = (signed char)va_arg(args, int);
	arg.char_count += ft_intputchar(res);
	reset_struct();
}
