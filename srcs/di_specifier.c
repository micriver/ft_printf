/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/06 14:21:20 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

//char	*di_ret_val(va_list args)
//{
//	char *res;
//
//	if (CHECK_BIT(arg.flgmods, SHOINT))
//		res = ft_itoa(va_arg(args, int));
//	else if ((CHECK_BIT(arg.flgmods, LNGLNG)) || (CHECK_BIT(arg.flgmods, LONGINT)))
//		res = ft_long_itoa(va_arg(args, long long int));
//	else
//		res = ft_itoa(va_arg(args, int));
//	//send to formatting stuff with rj or lj and precision or width handling
//	//res = di_print(res);
//	return (res);
//}

void	di_print(char *src)
{
	char *res;

	res = ft_strnew(ft_strlen(src));
	//CHECK FOR LEFT JUST OR RIGHT JUST FIRST
	if (arg.precision) 
	{
		//create string with (precision/THE MINIMUM) amount of digits
		if (arg.precision > (int)ft_strlen(src))
			res = leading_zeros_spaces(res, src, ft_strlen(src));
	}
	//precision has been handled
	else if (arg.width)
	{
		if (arg.width > (int)ft_strlen(res))
			res = leading_zeros_spaces(res, src, ft_strlen(src));
	}
	else
		ft_strcpy(res, src);
	arg.char_count += ft_strlen(res);
	ft_putstr(res);
	reset_flags();
}

void	di_ret_val(va_list args)
{
	char *res;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		res = ft_itoa(va_arg(args, int));
	else if ((CHECK_BIT(arg.flgmods, LNGLNG)) || (CHECK_BIT(arg.flgmods, LONGINT)))
		res = ft_long_itoa(va_arg(args, long long int));
	else
		res = ft_itoa(va_arg(args, int));
	//send to formatting stuff with rj or lj and precision or width handling
	di_print(res);
	//return (res);
}

//precision string printing will go here
//lj_strncpy will go here
//rj_strncpy will go here
//arg.char_count will go here
//ft_putstr will go here



	//if (arg.precision) //create string with (precision) amount of digits
	//{
	//	if (arg.precision > (int)ft_strlen(src))
	//		res = leading_zeros_spaces(res, src, ft_strlen(src));
	//	else
	//		ft_strcpy(res, src);
	//}
	//if (arg.width) //create string with (width) amount of characters
	//{
	////	if (arg.width > arg.precision)
	////		//create the precision string first
	//	if (arg.width > (int)ft_strlen(src))
	//		res = leading_zeros_spaces(res, src, ft_strlen(src));
	//	else
	//		ft_strcpy(res, src);
	//}
	////handle precision string building here
	////if (arg.precision) //create string with (precision) amount of digits
	////{
	////	if (arg.precision > (int)ft_strlen(src))
	////		res = leading_zeros_spaces(res, src, ft_strlen(src));
	////	else
	////		ft_strcpy(res, src);
	////}
	////if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, ZERO_F))
	////	res = prependchar('-', (ft_strcpy(res, src)));
	//else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, PLUS_F))
	//	res = prependchar('+', (ft_strcpy(res, src)));
	//else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, INVP_F) && res[0] != '-')
	//{
	//	if (CHECK_BIT(arg.flgmods, ZERO_F))
	//		res = prependchar(' ', src);
	//}
	//else
	//	ft_strcpy(res, src);
	////return (res);
	//ft_putstr(res);
