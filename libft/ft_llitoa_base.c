/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_llitoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 16:10:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/16 16:13:12 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_llitoa_base(long long int num, char *str, int base, int i)
{
	long long int	rem;
	long long int	temp;
	long long int	length;
	int				sign;

	temp = num;
	sign = 1;
	length = 1;
	while (temp /= base)
		length++;
	str = ft_strnew(length);
	if (num == 0)
	{
		str[i] = '0';
		str[i + 1] = '\0';
		return (str);
	}
	while (num != 0)
	{
		rem = (num % base);
		str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
		num = (num / base);
	}
	str[i] = '\0';
	return (ft_strrev(str));
}
