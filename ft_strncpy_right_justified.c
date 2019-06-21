/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy_right_justified.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:21:59 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/21 14:24:54 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

char	*rj_strncpy(char *src, size_t n)
{
	char *dest;
	size_t i;
	size_t x;
	int arg_size;

	arg_size = ft_strlen(src);
	dest = ft_strnew(n + arg_size);
	i = 0;
	x = 0;
	if (src[0] == '-')
	{
		dest[i] = '-';
		src[0] = '0';
		i++;
	}
	else
	{
		i = 0;
		x = 0;
	}
	while (i < (n - arg_size))
		dest[i++] = '0';
	while (src[x])
		dest[i++] = src[x++];
	printf("The width given is: %zu\n", n);
	printf("%zu\n", ft_strlen(dest));
	return (dest);
}

int		main()
{
	char src[] = "-7";
	//char dest[] = "";
	printf("argument is: %s\n", src);
//	printf("printed string is: %s\n", dest);
	printf("%s\n", rj_strncpy(src, 5));
	//printf("argument is now: %s\n", src);
	//printf("printed string is now: %s\n", dest);
	return (0);
}
