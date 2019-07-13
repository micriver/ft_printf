/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:33:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/12 18:13:23 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

int	ft_printf(char *fmt, ...)
{
	va_list args;
	int i;
	va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			char *argstring;
			argstring = conversion(&i, fmt, args);
			ft_putstr(argstring);
			i += 1;
		}
		ft_putchar(fmt[i]);
		i++;
	}
	va_end(args);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		//int x = 3;
		int x = ft_atoi(av[1]);
		//char *s1 = av[1];
		//int y = 424242;
		//int z = 5;
		//char s1[] = "Here is where % through your arguments...\n";

		//ft_printf("1, 2, %+010d\n", x, y, z);
		ft_printf("%+010d\n", x);
		printf("%+010d\n", x);
		//ft_printf(s1, x);
		(printf("The width value in our struct is: %d\n", args.width));
		(printf("The precision value in our struct is: %d\n", args.precision));
		printf("\nsize of regular structure = %lu\n", sizeof(args));
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
	}
	else
		printf("you fucked up\n");
	return (0);
}


/*
int		main()
{
	char str1[] = "%-10hd\n";
	int a = 1; //start at one to skip over % sign at the (0)th index
	long long int c = 1; //start at one to skip over % sign at the (0)th index
	//float b = 1.18927928739182749827987; //start at one to skip over % sign at the (0)th index
	printf("String to parsed: %%-10hd\n");
	printf("(a), our starting index in the string, = %d\n", a);
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
*/
