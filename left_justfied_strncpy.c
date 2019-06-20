/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 13:58:45 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/20 14:06:22 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../projects/ft_printf/libft/libft.h"
#include <stdio.h>

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t i;

	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = 'x';
		i++;
	}
	return (dest);
}

int		main()
{
	char src[] = "7";
	char dest[] = "";
	printf("argument is: %s\n", src);
//	printf("printed string is: %s\n", dest);
	ft_strncpy(dest, src, 5);
	//printf("argument is now: %s\n", src);
	printf("printed string is now: %s\n", dest);
	return (0);
}
