/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:15:22 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/30 18:18:37 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdint.h>

int64_t		u_return_value(va_list args)
{
	uint64_t u;

	u = 0;
	if (CHECK_BIT(arg.flgmods, SHOINT))
		u = ((unsigned short int)va_arg(args, unsigned int));
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		u = ((unsigned long int)va_arg(args, uint64_t));
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		u = (va_arg(args, unsigned long long int));
	else
		u = ((unsigned int)va_arg(args, int));
	return (u);
}

//#include "libft.h"

//char	*ft_ull_itoa(unsigned long long int n)
//{
//	unsigned long long int sign;
//	unsigned long long int length;
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
//		str[0] = '0';
//	//	return (NULL);
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

char	*u_specifier(int64_t u)
{
	char *result;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_itoa(u);
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		result = ft_itoa(u);
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		result = ft_ull_itoa(u);
	else
		result = ft_long_itoa(u);
	return (result);
}

