/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:01:13 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/07 14:37:10 by mirivera         ###   ########.fr       */
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
				case 'c': //chars
				{
					//placing the character given as an arg in the main into the buf that will 
					buf[j++] = (char)va_arg(args, int);
					break;
				}
				// case 'd': //integers
				// {
				// 	buf[j++] = (char)va_arg(args, int);
				// 	break;
				// }
				// default:
					// break;
			}
		}
		else
			//copy's fmt string into buffer until we get to '%', building the string to print!
			//case 's' to copy the string from the fmt to our buffer to be printed
			buf[j++] = fmt[i];
			// ft_strcpy(buf, fmt);
	}
	ft_putstr(buf);
	va_end(args);
}

int		main(void)
{
	char a = 'A';
	ft_printf("This is the test for a char: %c\n", a);
	return (0);
}