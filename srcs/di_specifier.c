/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/25 18:44:58 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
//#include <stdint.h>

//char	*ft_long_itoa(int64_t n)
//{
//	int64_t	length;
//	int64_t sign;
//	char	*str;
//
//	sign = n;
//	length = 1;
//	while (sign /= 10)
//		length++;
//	sign = n < 0 ? 1 : 0;
//	length = n < 0 ? length += 1 : length;
//	str = ft_strnew(length);
//	if (!str)
//		return (NULL);
//	if (sign)
//		str[0] = '-';
//	n = n < 0 ? n *= -1 : n;
//	while (--length >= sign)
//	{
//		str[length] = (n >= 10) ? (n % 10) + 48 : n + 48;
//		n /= 10;
//	}
//	str[ft_strlen(str)] = '\0';
//	return (str);
//}

char	*di_specifier(int64_t di)
{
	char *result;

	//if (CHECK_BIT(arg.flgmods, SHOINT))
	//	result = ft_itoa((short int)va_arg(args, int64_t));
	//else if (CHECK_BIT(arg.flgmods, LONGINT))
	//	result = ft_itoa((long int)va_arg(args, int64_t));
	//else if (CHECK_BIT(arg.flgmods, LNGLNG))
	result = ft_long_itoa(di);
	return (result);
}

