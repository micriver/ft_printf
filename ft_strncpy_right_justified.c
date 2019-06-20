/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:58:45 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/20 15:16:45 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../projects/ft_printf/libft/libft.h"
#include <stdio.h>

char	*my_strncpy(char *src, size_t n)
{
	char *dest;
	size_t i;
	size_t x;
	int arg_size;

	arg_size = ft_strlen(src);
	dest = ft_strnew(n + arg_size);
	i = 0;
	while (i < (n - arg_size))
		dest[i++] = '0';
	x = 0;
	while (src[x])
		dest[i++] = src[x++];
	printf("The width given is: %zu\n", n);
	printf("%zu\n", ft_strlen(dest));
	return (dest);
}

int		main()
{
	char src[] = "7777";
	//char dest[] = "";
	printf("argument is: %s\n", src);
//	printf("printed string is: %s\n", dest);
	printf("%s\n", my_strncpy(src, 10));
	//printf("argument is now: %s\n", src);
	//printf("printed string is now: %s\n", dest);
	return (0);
}
