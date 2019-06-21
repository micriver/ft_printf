/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_justfied_strncpy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:23:45 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/21 13:31:29 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>

char	*lj_strncpy(char *src, size_t n)
{
	char *dest;
	size_t i;
	size_t x;
	int arg_size;

	arg_size = ft_strlen(src);
	dest = ft_strnew(n + arg_size);
	x = 0;
	i = 0;
	while (src[x])
		dest[i++] = src[x++];
	while (i < n)
		dest[i++] = '0';
	printf("The width given is: %zu\n", n);
	printf("%zu\n", ft_strlen(dest));
	return (dest);
}

int		main()
{
	char src[] = "821000";
	//char dest[] = "";
	printf("argument is: %s\n", src);
//	printf("printed string is: %s\n", dest);
	printf("%s\n", lj_strncpy(src, 10));
	//printf("argument is now: %s\n", src);
	//printf("printed string is now: %s\n", dest);
	return (0);
}
