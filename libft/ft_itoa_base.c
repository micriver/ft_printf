/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 11:00:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/06 20:42:04 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function is used primarily for all base conversions other than decimal.
**
** This function converts an integer value to a string.
**
** The (base) parameter specifies the conversion base. The individual
** digits are processed in a while loop and their characters
** placed in the given string. The remainders are the digits
** of the converted string.
**
** Since this is not decimal, values are considered unsigned.
**
** Line 35 determines the conversion to happen (binary, hexadecimal, etc.)
** by dividing the digit by the given base.
*/

char		*ft_itoa_base(int64_t num, int base, int i)
{
	int64_t		rem;
	int			sign;
	int64_t		temp;
	int			length;
	char		*str;

	if (num < 0)
		num = num * -1;
	temp = num;
	sign = 1;
	length = 1;
	while (temp /= base)
		length++;
	str = ft_strnew(length);
	while (num != 0)
	{
		rem = (num % base);
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = (num / base);
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
