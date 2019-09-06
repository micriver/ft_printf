/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ullitoa.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:04:29 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/06 15:36:00 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_ullitoa(unsigned long long int n)
{
	unsigned long long int	sign;
	unsigned long long int	length;
	char					*str;

	sign = n;
	length = 1;
	while (sign /= 10)
		length++;
	str = ft_strnew(length);
	if (!str)
		str[0] = '0';
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
