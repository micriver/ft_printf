/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:52:03 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/05 17:19:25 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	s_conv(va_list args)
{
	char *res;

	res = va_arg(args, char *);
	if (res == NULL && !arg.width)
	{
		arg.char_count += ft_intputstr("(null)");
		free(res);
	}
	else if ((res == NULL) && arg.width <= 6 && !arg.precision)
	{
		arg.char_count += ft_intputstr("(null)");
		free(res);
	}
	else if ((res == NULL) && arg.width <= 6 && arg.precision)
		s_form("(null)");
	else if ((res == NULL) && arg.width > 6)
		s_form("(null)");
	else
		s_form(res);
}
