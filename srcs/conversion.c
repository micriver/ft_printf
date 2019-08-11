/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/11 15:36:12 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

void	conversion(int *i, char *str, va_list args)
{
	(*i)++;
	master_pars(str, i);
	//place a while loop here where you loop through n
	//and a list of specifiers in a string
	//DISPATCH TABLE!!!!
	//while loop and dispatch table here
//	int n;
//
//	n = 0;
//	while (CONV_SPECS[n])
//	{
//		if (arg.conv == CONV_SPECS[n])
//			printf("conversion char in the struct = %c\n", arg.conv);
//		n++;
//	}
	//printf("You're conversion character is %c\n", arg.conv);
	if ((arg.conv = 'd') || (arg.conv = 'i'))
		dui_ret_val(args);
	//if (arg.conv = 'u')
	//if (ft_strcmp(arg.conv, "u") == 0)
	else if (arg.conv == 'u')
	{
		if (CHECK_BIT(arg.flgmods, LNGLNG))
			ull_ret_val(args);
		else
			u_ret_val(args);
	}
	//else if (str[*i] == 's')
	//	result = s_specifier(args);
	//else
	//	result = NULL; 
	//return (result);
}

