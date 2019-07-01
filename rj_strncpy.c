/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rj_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:14:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/01 12:58:35 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define CHECK_BIT(var,pos) ((var >> pos) & 1) 
#define SET_BIT(var,pos) (var |= 1 << pos) 
#define TOGGLE_BIT(var,pos) (var ^= (1 << pos)) 

#define ZERO_F (0)
#define MINUS_F (1)
#define PLUS_F (2)
#define SHARP_F (3)
#define INVP_F (4)
#define SPACE (' ')

struct arguments
{
	int arg1 : 16; //make sure that you set the bit width to only the amount of bits you actually need!!! eg, the # of flags/modifiers you'll be using
	int arg2 : 16;
} args;

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
		}
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
	while (i < (width - arg_size))
	{
		dest[i] = ' ';
		(CHECK_BIT(args.arg1, ZERO_F)) ? (dest[i++] = '0') : (dest[i++]);
	}
	dest = lead_zero_negsign(dest, src, (width - arg_size));
	return (dest);
}

int		main()
{
//	SET_BIT(args.arg1, ZERO_F);
	char src[] = "8899";
	int x = 8899;
	//char dest[] = "";
	//printf("argument is: %s\n", src);
//	printf("printed string is: %s\n", dest);
	//printf("%s\n", rj_strncpy(src, 5));
	printf("ft_printf:%s\n", rj_strncpy(src, 10));
	if (CHECK_BIT(args.arg1, ZERO_F))
		printf("printf   :%010d\n", x);
	else
		printf("printf   :%10d\n", x);
	//printf("argument is now: %s\n", src);
	//printf("printed string is now: %s\n", dest);
	return (0);
}
