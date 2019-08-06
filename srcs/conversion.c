/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/05 17:31:51 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>
#include <time.h>

//char	*conversion(int *i, char *str, va_list args)
//{
//	char *result;
//
//	master_pars(str, i);
//	//place a while loop here where you loop through n
//	//and a list of specifiers in a string
//	//while loop and dispatch table here
//	if ((arg.conv = 'd') || (arg.conv = 'i'))
//		//result = di_ret_val(args);
//		di_ret_val(args);
//	else if (str[*i] == 'u')
//	{
//		if (CHECK_BIT(arg.flgmods, LNGLNG))
//			result = ull_ret_val(args);
//		else
//			result = u_ret_val(args);
//	}
//	else if (str[*i] == 's')
//		result = s_specifier(args);
//	else
//		result = NULL; 
//	return (result);
//}

void	conversion(int *i, char *str, va_list args)
{
	//char *result;

	master_pars(str, i);
	//place a while loop here where you loop through n
	//and a list of specifiers in a string
	//while loop and dispatch table here
	if ((arg.conv = 'd') || (arg.conv = 'i'))
		//result = di_ret_val(args);
		di_ret_val(args);
	//else if (str[*i] == 'u')
	//{
	//	if (CHECK_BIT(arg.flgmods, LNGLNG))
	//		result = ull_ret_val(args);
	//	else
	//		result = u_ret_val(args);
	//}
	//else if (str[*i] == 's')
	//	result = s_specifier(args);
	//else
	//	result = NULL; 
	//return (result);
}

