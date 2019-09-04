/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base_up.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:53:56 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 22:54:11 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This itoa base makes the hexadecimal values all uppercase ascii characters
**
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

char		*ft_itoa_base_up(int64_t num, char *str, int base, int i)
{
	int64_t		rem;
	int			sign;
	int64_t		temp;
	int			length;

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
		str[i++] = (rem > 9) ? (rem - 10) + 'A' : rem + '0';
		num = (num / base);
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
