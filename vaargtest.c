/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vaargtest.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/03 14:22:44 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/09 16:04:13 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <string.h>

int	printf (const char *format, ...)
{
	va_list args;
	int done;

	va_start (args, format);
	//vfprintf is TAKING a va_list type variable 'args' which is all the arguments being passed in the parameters above
	done = vfprintf (stdout, format, args); //<------ THIS IS WHAT I NEED TO PASS TO CONVERSION.C!!!!!

	//argstring = conversion(fmt, args, *i);

	va_end (args);

	return done;
}

int	printf2 (const char *format, ...)
{
	va_list args;
	int done;

	va_start (args, format);
	while (fmt)
	{
		done = vfprintf (stdout, format, args); //<------ THIS IS WHAT I NEED TO PASS TO CONVERSION.C!!!!!
	}
	va_end (args);

	return done;
}

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

int		main()
{
	printf ("figuring it all out as I go...\n");
	print_ints(3, 25, 26, 312);
	print_ints(2, 256, 512);
	print_ints(7, 2, 4, 7, 1);
	return (0);
}
