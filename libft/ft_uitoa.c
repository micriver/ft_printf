/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:55:05 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/31 16:13:04 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_uitoa(unsigned long int n)
{
	unsigned long int sign;
	unsigned long int length;
	char	*str;

	sign = n;
	length = 1;
	while (sign /= 10)
		length++;
	str = ft_strnew(length);
	if (!str)
		str[0] = '0';
	n = n < 0 ? n *= -1 : n;
	while (--length >= sign)
	{
		str[length] = (n >= 10) ? (n % 10) + 48 : n + 48;
		n /= 10;
		if (length == 0)
			break ;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
