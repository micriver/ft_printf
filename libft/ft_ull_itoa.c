/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ull_itoa.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 17:59:23 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/30 18:06:49 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ull_itoa(unsigned long long int n)
{
	unsigned long long int sign;
	unsigned long long int length;
	char	*str;

	sign = n;
	length = 1;
	while (sign /= 10)
		length++;
	sign = n < 0 ? 1 : 0;
	length = n < 0 ? length += 1 : length;
	str = ft_strnew(length);
	if (!str)
		str[0] = '0';
	//	return (NULL);
	if (sign)
		str[0] = '-';
	n = n < 0 ? n *= -1 : n;
	while (--length >= sign)
	{
		str[length] = (n >= 10) ? (n % 10) + 48 : n + 48;
		n /= 10;
	}
	str[ft_strlen(str)] = '\0';
	return (str);
}
