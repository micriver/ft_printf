/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:33:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/13 16:46:30 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdarg.h>

int		ft_printf(char *fmt, ...)
{
	va_list args;
	int i;
	arg.char_count = 0;
	va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			conversion(&i, fmt, args);
		if (fmt[i] == '\0')
			break ;
		else
		{
			ft_putchar(fmt[i]);
			arg.char_count++;
			i++;
		}
	}
	va_end(args);
	return (arg.char_count);
}

