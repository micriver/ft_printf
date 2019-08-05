/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/05 11:33:56 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//on the dui branch now!

#include "../headers/ft_printf.h"

char	*di_ret_val(va_list args)
{
	char *result;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_itoa(va_arg(args, int));
	else if ((CHECK_BIT(arg.flgmods, LNGLNG)) || (CHECK_BIT(arg.flgmods, LONGINT)))
		result = ft_long_itoa(va_arg(args, long long int));
	else
		result = ft_itoa(va_arg(args, int));
	//send to formatting stuff with rj or lj and precision or width handling
	//result = di_print(result);
	return (result);
}

//precision string printing will go here
//lj_strncpy will go here
//rj_strncpy will go here
//arg.char_count will go here
//ft_putstr will go here

char	*rj_strncpy(char *src)
{
	char *dest;

	dest = ft_strnew(ft_strlen(src));
	if (arg.width) //create string with (width) amount of characters
	{
		if (arg.width > (int)ft_strlen(src))
			dest = leading_zeros_spaces(dest, src, ft_strlen(src));
		else
			ft_strcpy(dest, src);
	}
	//handle precision string building here
	//if (arg.precision) //create string with (precision) amount of digits
	//{
	//	if (arg.precision > (int)ft_strlen(src))
	//		dest = leading_zeros_spaces(dest, src, ft_strlen(src));
	//	else
	//		ft_strcpy(dest, src);
	//}
	//if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, ZERO_F))
	//	dest = prependchar('-', (ft_strcpy(dest, src)));
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, PLUS_F))
		dest = prependchar('+', (ft_strcpy(dest, src)));
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, INVP_F) && dest[0] != '-')
	{
		if (CHECK_BIT(arg.flgmods, ZERO_F))
			dest = prependchar(' ', src);
	}
	else
		ft_strcpy(dest, src);
	return (dest);
}
