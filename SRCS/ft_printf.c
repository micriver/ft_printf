/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 16:33:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/12 17:37:24 by mirivera         ###   ########.fr       */
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
