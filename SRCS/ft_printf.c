/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:01:13 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/07 14:15:08 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_printf.h"

void	ft_printf(const char *fmt, ...)
{
	va_list args;
	char *buf;
	int i;
	int j;

	buf = (ft_strnew((ft_strlen(fmt))));
	va_start(args, fmt);
	i = -1;
	j = 0;
	while (buf && fmt[++i])
	{
		if (fmt[i] == '%')
		{
			i++;
			switch (fmt[i])
			{
				case 'c': 
				{
					buf[j++] = (char)va_arg(args, int);
					break;
				}
				// default:
					// break;
			}
		}
		else
			buf[j++] = fmt[i];
			// ft_strcpy(buf, fmt);
	}
	ft_putstr(buf);
	va_end(args);
}

int		main(void)
{
	char a = 'A';
	ft_printf("char = %c\n", a);
	return (0);
}