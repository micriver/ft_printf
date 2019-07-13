/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_justfied_strncpy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:23:45 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/12 18:43:45 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../HEADERS/ft_printf.h"
#include "../HEADERS/libft.h"
#include <stdio.h>

char	*lj_strncpy(char *src, size_t n)
{
	char *dest;
	size_t i;
	int arg_size;

	arg_size = ft_strlen(src);
	dest = ft_strnew(n + arg_size);
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	if ((size_t)arg_size > n)
		return (dest);
	while (i < n)
		dest[i++] = ' ';
	//printf("The width given is: %zu\n", n);
	//printf("%zu\n", ft_strlen(dest));
	return (dest);
}

int		main()
{
	char src[] = "821000";
	//char dest[] = "";
//	printf("argument is: %s\n", src);
//	printf("printed string is: %s\n", dest);
	printf("ft_printf:%s\n", lj_strncpy(src, 10));
	//printf("argument is now: %s\n", src);
	//printf("printed string is now: %s\n", dest);
	printf("printf   :%-10s\n", src);
	return (0);
}
