/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:21:27 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/03 18:46:08 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HEADERS/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

int	ft_printf(char *fmt, ...)
{
	va_list args;
	int i;
	char *argstring = NULL;
	va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			//***create an argument member in the struct!!!!***
			//OR CREATE A CLEAR BIT FUNCTION AND USE SAME STRUCTURE MEMBER FOR EACH FLAG EVERYTIME IT LOOPS
			i++; //iterate to the first flag
			argstring = conversion(fmt, &i);
			i += ft_strlen(argstring);
		}
		ft_putchar(fmt[i]);
		i++;
	}
	va_end(args);
	return (0);
}

// flag parser
// width modifier
// precision modifier
// length modifier parser
// conversion specifier parser





int		main(int ac, char **av)
{
	//clock_t t;
	if(ac == 3)
	//if(ac == 2)
	{
		//(void)av;
		//(void)ac;
		int width = 10;
		//SET_BIT(args.arg1, ZERO_F);
		//SET_BIT(args.arg1, PLUS_F);
		//char src[] = "42";
		int x = 42;
		//int x = ft_atoi(av[1]);
		ft_printf("%0d", x);
		//printf("ft_printf:%s\n", rj_strncpy(av[1], width));
		if (CHECK_BIT(args.arg1, ZERO_F) && CHECK_BIT(args.arg1, PLUS_F))
			printf("printf   :%+0*d\n", width, x);
		else if (CHECK_BIT(args.arg1, ZERO_F))
			printf("printf   :%0*d\n", width, x);
		else if (CHECK_BIT(args.arg1, PLUS_F))
			printf("printf   :%+*d\n", width, x);
		//else
			//printf("printf   :%*s\n", width, aplha);
	}
	return (0);
}
