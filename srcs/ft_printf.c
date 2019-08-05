/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:33:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/05 11:33:59 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <time.h>

int		ft_printf(char *fmt, ...)
{
	va_list args;
	char *argstring;
	int i;
	arg.char_count = 0;
	va_start(args, fmt);
	i = 0;
	while (fmt[i])
	{
		if (fmt[i] == '%')
		{
			i++;
			argstring = conversion(&i, fmt, args);
			//lines 33 - 38 can go into each conversion specifier's .c file
			if (CHECK_BIT(arg.flgmods, MINUS_F))
				argstring = lj_strncpy(argstring);
			else
				argstring = rj_strncpy(argstring);
			ft_putstr(argstring);
			arg.char_count += ft_strlen(argstring);
			i += 1;
			reset_flags();
		}
		if (fmt[i] == '\0')
			break ;
		else
		{
			ft_putchar(fmt[i]);
			i++;
		}
		arg.char_count++;
		//i++;
	}
	va_end(args);
	return (arg.char_count);
}

//int		main(void)
//{
//	//if (ac == 2)
//	//{
//	int x = 3;
//	//	short int x = ft_atoi(av[1]);
//	//	//long int x = ft_atoi(av[1]);
//	//	(void)av;
//	//	(void)ac;
//	//	long long x = 100000000000LL;
//	//	long x = 100000000000LL;
//	//	//char *s1 = av[1];
//	//	//int y = 424242;
//	//	//int z = 5;
//	//	//char s1[] = "Here is where % through your arguments...\n";
//
//	//	//ft_printf("1, 2, %+010d\n", x, y, z);
//		//ft_printf("FT_PRINTF:%d\n", x);
//		//printf("PRINTF   :%d\n", x);
//	//	//ft_printf(s1, x);
//	//	(printf("The width value in our struct is: %d\n", arg.width));
//	//	(printf("The precision value in our struct is: %d\n", arg.precision));
//	//	printf("\nsize of regular structure = %lu\n", sizeof(arg));
//	//	printf("SHARP flag state is: %d\n", CHECK_BIT(arg.flgmods, SHARP_F));
//	//	printf("MINUS flag state is: %d\n", CHECK_BIT(arg.flgmods, MINUS_F));
//	//	printf("PLUS flag state is: %d\n", CHECK_BIT(arg.flgmods, PLUS_F));
//	//	printf("INVP flag state is: %d\n", CHECK_BIT(arg.flgmods, INVP_F));
//	//	printf("ZERO flag state is: %d\n", CHECK_BIT(arg.flgmods, ZERO_F));
//	//	printf("SGNDCHR flag state is: %d\n", CHECK_BIT(arg.flgmods, SGNDCHR));
//	//	printf("SHOINT flag state is: %d\n", CHECK_BIT(arg.flgmods, SHOINT));
//	//	printf("LONGINT flag state is: %d\n", CHECK_BIT(arg.flgmods, LONGINT));
//	//	printf("LNGLNG flag state is: %d\n", CHECK_BIT(arg.flgmods, LNGLNG));
//	//	printf("LNG_D flag state is: %d\n", CHECK_BIT(arg.flgmods, LNG_D));
//	//}
//	//else
//	//	ft_printf("Retry with an integer!\n");
//	ft_printf("%d\n", x);
//	//printf("%d\n", x);
//	return (0);
//}

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
