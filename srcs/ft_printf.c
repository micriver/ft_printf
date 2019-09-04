/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:33:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/04 15:07:25 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		ft_printf(char *fmt, ...)
{
	va_list		args;
	int			i;

	arg.char_count = 0;
	va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
			conversion(&i, fmt, args);
		else if (fmt[i] == '\0')
			break ;
		else
			arg.char_count += ft_intputchar(fmt[i++]);
	}
	va_end(args);
	return (arg.char_count);
}
