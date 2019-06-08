/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:01:13 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/08 14:11:21 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_printf.h"

void	ft_printf(const char *fmt, ...)
{
	va_list args;
	char *buf;
	char *temp;
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
					//placing the character given as an arg into the buf that will be printed out
					buf[j++] = (char)va_arg(args, int);
					break;
				}
				case 'd': 
				{
					//itoa returns string
 	 				temp = ft_itoa(va_arg(args, int));
					//copying the string
 					ft_strcpy(&buf[j], temp);
 					j += ft_strlen(temp);
					break;
				}
			}
		}
		else
			//iterates through and copy's fmt string into buffer string until we get to '%', building the string to print!
			//ALSO the case 's' to copy the string from the fmt to our buffer to be printed
			buf[j++] = fmt[i];
	}
	ft_putstr(buf);
	va_end(args);
}

int		main(void)
{
	// char a = 'A';
	int b = 10;
	// ft_printf("This is the test for a char: %c\n", a);
	ft_printf("%d\n", b);
	return (0);
}