/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:52:03 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/29 22:58:29 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	s_conv(va_list args)
{
	char *res;

	res = va_arg(args, char *);
	if (res == NULL)
		arg.char_count += ft_intputstr("(null)");
	else
		arg.char_count += ft_intputstr(res);
	reset_struct();
	free(res);
}
