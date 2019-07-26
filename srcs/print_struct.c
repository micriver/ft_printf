/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 13:07:22 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/25 18:06:53 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

void	print_struct(void)
{
//	int i = 0;

	//while (i < arg.width.precision.char_count)
	//{
	//	printf("%d\n", arg.width);
	//	i++;
	//}
	printf("\n width = %d\n", arg.width);
	printf("\n precision = %d\n", arg.precision);
	printf("\n char_count = %d\n", arg.char_count);
	printf("SHARP flag state is: %d\n", CHECK_BIT(arg.flgmods, SHARP_F));
	printf("MINUS flag state is: %d\n", CHECK_BIT(arg.flgmods, MINUS_F));
	printf("PLUS flag state is: %d\n", CHECK_BIT(arg.flgmods, PLUS_F));
	printf("INVP flag state is: %d\n", CHECK_BIT(arg.flgmods, INVP_F));
	printf("ZERO flag state is: %d\n", CHECK_BIT(arg.flgmods, ZERO_F));
	printf("SGNDCHR flag state is: %d\n", CHECK_BIT(arg.flgmods, SGNDCHR));
	printf("SHOINT flag state is: %d\n", CHECK_BIT(arg.flgmods, SHOINT));
	printf("LONGINT flag state is: %d\n", CHECK_BIT(arg.flgmods, LONGINT));
	printf("LNGLNG flag state is: %d\n", CHECK_BIT(arg.flgmods, LNGLNG));
	printf("LNG_D flag state is: %d\n", CHECK_BIT(arg.flgmods, LNG_D));
}

void	reset_flags(void)
{
	int i;

	i = 0;
	while (i < 9)	
	{
		if (CHECK_BIT(arg.flgmods, i))
			TOGGLE_BIT(arg.flgmods, i);
		i++;
	}
}

//int main() {
//   	print_struct();
//	return (0);
//}
