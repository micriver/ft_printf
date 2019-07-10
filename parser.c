/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:21:27 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/09 19:13:11 by mirivera         ###   ########.fr       */
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
			i++; //iterate to the first element to be parsed
			argstring = conversion(&i, fmt, args);
			ft_putstr(argstring)
			i += ft_strlen(argstring);
		}
		ft_putchar(fmt[i]);
		i++;
	}
	fmt[i] = '\0';
	va_end(args);
	return (0);
}
*/

/*
void print_ints(int num, ...)
{
	va_list args;

	//takes two arguments, the va list and the last required argument <---- this might be what i have to feed into my conversion function
	va_start(args, num); //pull off the arguments one by one, in the order they live on the stack

	//wow this is what I've been trying to confirm this whole time
	for (int i = 0; i < num; i++)
	{
		int value = va_arg(args, int); //treat "va_arg(x, x)" as a variable that has parameters, it can be passed into functions and it represents each argument respectively
		printf("%d: %d\n", i, value);
	}

	va_end(args);
}
*/

// flag parser
int		flag_parse(char *str, int *i)
{
	int *x;

	x = i;
	if (str[*x] == '.')
		return (0);
	while (!ft_isalnum(str[*x]) || str[*x] == '0') //we parse the parameters until we get to a conversion specifier
	{
		(str[*x] == '#') ? SET_BIT(args.flgmods, SHARP_F) : str[*x];
		(str[*x] == '-') ? SET_BIT(args.flgmods, MINUS_F) : str[*x];
		(str[*x] == '+') ? SET_BIT(args.flgmods, PLUS_F) : str[*x];
		(str[*x] == ' ') ? SET_BIT(args.flgmods, INVP_F) : str[*x];
		(str[*x] == '0') ? SET_BIT(args.flgmods, ZERO_F) : str[*x];
		(*x)++;
	}
	return (1);
}

// width modifier parser
int		width_parser(char *str, int *i)
{
	int y;
	int j;
	char *result;
	int *x;

	j = (*i);
	y = 0;
	x = i;
	if (str[*x] == '.')
		return (0);
	while (!(ft_isalpha(str[j])) && str[j + 1] != '.')
		(j)++;
	result = ft_strnew(j);
	while (!(ft_isalpha(str[*x])) && str[*x] != '.') //we parse the parameters until we get to a '.' or conv specifier
	{
		result[y] = str[*x];
		y++;
		(*x)++;
	}
	args.width = ft_atoi(result);
	return (1);
}

// precision modifier
int		precision_parser(char *str, int *i)
{
	int y;
	int j;
	char *result;
	int *x;

	j = (*i);
	y = 0;
	x = i;
	if (str[*x] != '.')
		return (0);
	else
		(*x) += 1;
	result = ft_strnew(j);
	while (!ft_isalpha(str[*x])) //we parse the parameters until we get to a conversion specifier
	{
		result[y] = str[*x];
		y++;
		(*x)++;
	}
	args.precision = ft_atoi(result);
	return (1);
}

// length modifier parser (hh), (h), (l), (ll), with diouxX and f with (l), (L) 
int		lengthmod_pars(char *str, int *i)
{
	int *x;

	x = i;
	if (str[*x] != 'h' && str[*x] != 'l' && str[*x] != 'L' )
		return (0);
	else
	{
		(str[*x] == 'h' && str[(*x) + 1] == 'h') ? SET_BIT(args.flgmods, SGNDCHR) : str[*x];
		if (str[*x] == 'h' && str[(*x) + 1] != 'h')
		{
			SET_BIT(args.flgmods, SHOINT);
			x++;
		}
		if (str[*x] == 'l' && str[(*x) + 1] != 'l')
		{
			SET_BIT(args.flgmods, LONGINT);
			x++;
		}
		(str[*x] == 'l' && str[(*x) + 1] == 'l') ? SET_BIT(args.flgmods, LNGLNG) : str[*x];
		(str[*x] == 'L') ? SET_BIT(args.flgmods, LNG_D) : str[*x];
	}
	return (1);
}

//master parser
void	master_pars(char *fmt, int *i)
{
	flag_parse(fmt, i);
	width_parser(fmt, i);
	precision_parser(fmt, i);
	lengthmod_pars(fmt, i);
}

int		main()
{
	char str1[] = "%-10hd\n";
	int a = 1; //start at one to skip over % sign at the (0)th index
	long long int c = 1; //start at one to skip over % sign at the (0)th index
	//float b = 1.18927928739182749827987; //start at one to skip over % sign at the (0)th index
	printf("(a), our index in the string, = %d\n", a);
	master_pars(str1, &a);
	//flag_parse(str1, &a);
	//width_parser(str1, &a);
	//precision_parser(str1, &a);
	//lengthmod_pars(str1, &a);
	(printf("The width value in our struct is: %d\n", args.width));
	(printf("The precision value in our struct is: %d\n", args.precision));
	printf("(a), our index after finding the width, = %d\n", a);
	//printf("(a), now = %d\n", a);
	//print out the bit states of my bitfield in the struct
	printf("\nsize of regular structure = %lu\n", sizeof(args));
	//printf("size of structure with bit field = %lu\n", sizeof(d2));
	printf("SHARP flag state is: %d\n", CHECK_BIT(args.flgmods, SHARP_F));
	printf("MINUS flag state is: %d\n", CHECK_BIT(args.flgmods, MINUS_F));
	printf("PLUS flag state is: %d\n", CHECK_BIT(args.flgmods, PLUS_F));
	printf("INVP flag state is: %d\n", CHECK_BIT(args.flgmods, INVP_F));
	printf("ZERO flag state is: %d\n", CHECK_BIT(args.flgmods, ZERO_F));
	printf("SGNDCHR flag state is: %d\n", CHECK_BIT(args.flgmods, SGNDCHR));
	printf("SHOINT flag state is: %d\n", CHECK_BIT(args.flgmods, SHOINT));
	printf("LONGINT flag state is: %d\n", CHECK_BIT(args.flgmods, LONGINT));
	printf("LNGLNG flag state is: %d\n", CHECK_BIT(args.flgmods, LNGLNG));
	printf("LNG_D flag state is: %d\n", CHECK_BIT(args.flgmods, LNG_D));
	printf("%+05lld\n", c);
	return (0);
}
