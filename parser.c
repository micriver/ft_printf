/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:21:27 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/08 10:52:23 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HEADERS/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

/*
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
			//create an argument member in the struct!!!!
			//OR CREATE A CLEAR BIT FUNCTION AND USE SAME STRUCTURE MEMBER FOR EACH FLAG EVERYTIME IT LOOPS
			i++; //iterate to the first element to be parsed
			argstring = conversion(&i, va_list(fmt, args));
			i += ft_strlen(argstring);
		}
		ft_putchar(fmt[i]);
		i++;
	}
	va_end(args);
	return (0);
}
*/

// flag parser
void	flag_parse(char *str, int *i)
{
	int *x;

	x = i;
	while (!ft_isalnum(str[*x]) || str[*x] == '0') //we parse the parameters until we get to a conversion specifier
	{
		(str[*x] == '#') ? SET_BIT(args.arg1, SHARP_F) : str[*x];
		(str[*x] == '-') ? SET_BIT(args.arg1, MINUS_F) : str[*x];
		(str[*x] == '+') ? SET_BIT(args.arg1, PLUS_F) : str[*x];
		(str[*x] == ' ') ? SET_BIT(args.arg1, INVP_F) : str[*x];
		(str[*x] == '0') ? SET_BIT(args.arg1, ZERO_F) : str[*x];
		(*x)++;
	}
}

// width modifier parser
void	width_parser(char *str, int *i)
{
	int y;
	int j;
	char *result;
	int *x;

	j = (*i);
	y = 0;
	x = i;
	while (!ft_isalpha(str[j]))
		(j)++;
	result = ft_strnew(j);
	while (!ft_isalpha(str[*x])) //we parse the parameters until we get to a conversion specifier
	{
		result[y] = str[*x];
		y++;
		(*x)++;
	}
	args.width = ft_atoi(result);
}

// precision modifier
// length modifier parser
// conversion specifier parser

int		main()
{
	char str1[] = "%-+0100d";
	int a = 1; //start at one to skip over % sign at the (0)th index
	printf("(a), our index in the string, = %d\n", a);
	flag_parse(str1, &a);
	printf("(a), now = %d\n", a);
	width_parser(str1, &a);
	printf("The width value in our struct is: %d\n", args.width);
	printf("(a), our index after finding the width, = %d\n", a);
	//printf("(a), now = %d\n", a);
	//print out the bit states of my bitfield in the struct
	printf("SHARP flag state is: %d\n", CHECK_BIT(args.arg1, SHARP_F));
	printf("MINUS flag state is: %d\n", CHECK_BIT(args.arg1, MINUS_F));
	printf("PLUS flag state is: %d\n", CHECK_BIT(args.arg1, PLUS_F));
	printf("INVP flag state is: %d\n", CHECK_BIT(args.arg1, INVP_F));
	printf("ZERO flag state is: %d\n", CHECK_BIT(args.arg1, ZERO_F));
	printf("%+100d\n", a);
/*
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
*/
	return (0);
}
