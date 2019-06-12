/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 09:01:13 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/11 20:00:08 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_printf.h"
#include <stdio.h>

void	ft_printf(const char *fmt, ...)
{
	va_list args;
	char *buf;
	char *temp;
	//void *s = NULL;
	int i;
	int j;
	size_t width = 0;

	buf = ft_strnew(ft_strlen(fmt));
	va_start(args, fmt);
	i = -1;
	j = 0;
	while (buf && fmt[++i])
	{
		if (fmt[i] == '%')
		{
			i++;
			//print percent signs
			if (fmt[i] == '%')
				ft_putchar('%');
			if (ft_isdigit(fmt[i]))
			{
				width = ft_atoi(&fmt[i]);
				char *temp2 = NULL;
				ft_memset(temp2 = ft_strnew(width), ' ', (width - 1));
				temp = ft_strcat(temp2, ft_itoa(va_arg(args, int)));
				ft_strcpy(&buf[j], temp);
				j += ft_strlen(temp);
			}
			switch (fmt[i])
			{
				case 'c': //chars
				{
					//placing the character given as an arg into the buf that will be printed out
					buf[j++] = (char)va_arg(args, int);
					break;
				}
				case 'd': //integers
				{
					//itoa returns string
					temp = ft_itoa(va_arg(args, int));
					//copying the string to buf AT (j)'s current index
					ft_strcpy(&buf[j], temp);
					//setting the index  value to the length of temp to continue printing the rest of the fmt string after the value has been placed
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
	int b = 7;
   	//char c = '%';
	ft_printf("%3d\n", b);
	printf("%3d\n",b);
	return (0);
}

/*
//	void *a;
// ft_printf("This is the test for a char: %c\n", a);
//	ft_putstr(a);
	*/
