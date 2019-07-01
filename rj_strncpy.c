/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rj_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:14:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/01 14:20:59 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HEADERS/ft_printf.h"
#include <stdio.h>

char	*lead_zero_negsign(char *dest, char *src, int size)
{
	int y;
	int j;

	y = 0;
	j = 0;
	while (src[y])
	{
		if (src[0] == '-' && (CHECK_BIT(args.arg1, ZERO_F)))
		{
			dest = prefixchar('-', dest);
			src[0] = '0';
			//size += 1;
			//src += 1;
		}
		else if (ft_atoi(src) >= 0 && CHECK_BIT(args.arg1, PLUS_F))
			dest = prefixchar('+', dest);
		dest[size++] = src[y++];
	}
	return (dest);
}

char	*rj_strncpy(char *src, size_t width)
{
	char *dest;
	size_t i;
	size_t x;
	int arg_size;

	arg_size = ft_strlen(src);
	dest = ft_strnew(width + arg_size);
	i = 0;
	x = 0;
	if (width > (size_t)arg_size)
	{
		while (i < (width - arg_size))
		{
			dest[i] = ' ';
			(CHECK_BIT(args.arg1, ZERO_F)) ? (dest[i++] = '0') : (dest[i++]);
		}
		dest = lead_zero_negsign(dest, src, (width - arg_size));
	}
	while (src[i])
		dest[x++] = src[i++];
	return (dest);
}

int		main()
{
	int width = 10;
	SET_BIT(args.arg1, ZERO_F);
	//SET_BIT(args.arg1, PLUS_F);
	char src[] = "-8899";
	int x = -8899;
	//char dest[] = "";
	//printf("argument is: %s\n", src);
//	printf("printed string is: %s\n", dest);
	//printf("%s\n", rj_strncpy(src, 5));
	printf("ft_printf:%s\n", rj_strncpy(src, width));
	if (CHECK_BIT(args.arg1, ZERO_F))
		printf("printf   :%0*d\n", width, x);
	else
		printf("printf   :%*d\n", width, x);
	//printf("argument is now: %s\n", src);
	//printf("printed string is now: %s\n", dest);
	return (0);
}
