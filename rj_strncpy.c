/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rj_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:14:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/09 18:45:22 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HEADERS/ft_printf.h"
#include <stdio.h>
#include <time.h>

char	*prependchar(char c, char *str)
{
	unsigned int i;
	unsigned int j;
	char *pstr;

	pstr = ft_strnew(ft_strlen(str + 1));
	i = 0;
	j = 0;
	pstr[i] = c;
	while (pstr[i])
		pstr[++i] = str[j++];
	pstr[i] = '\0';
	return (pstr);
}

char	*insertplussign(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '0')
		i++;	
	str[i - 1] = '+';
	return (str);
}

char	*lead_zero_negsign(char *dest, char *src, int size)
{
	int y;

	y = 0;
	while (src[y])
	{
		if (ft_atoi(src) >= 0 && CHECK_BIT(args.arg1, PLUS_F) && dest[0] != '-')
		{
			if (CHECK_BIT(args.arg1, ZERO_F))
				dest = prefixchar('+', dest);
		}
		else if (src[0] == '-' && (CHECK_BIT(args.arg1, ZERO_F)))
		{
			dest = prefixchar('-', dest);
			src[0] = '0';
		}
		dest[size++] = src[y++];
	}
	if (!CHECK_BIT(args.arg1, ZERO_F) && CHECK_BIT(args.arg1, PLUS_F) \
			&& src[0] != '-')
		dest = insertplussign(dest);
	dest[size] = '\0';
	return (dest);
}

char	*leading_zeros_spaces(char *dest, char *src, int width, int arg_size)
{
	int i;

	i = 0;
	while (i < (width - arg_size))
	{
		dest[i] = ' ';
		(CHECK_BIT(args.arg1, ZERO_F)) ? (dest[i++] = '0') : (dest[i++]);
	}
	return (dest = lead_zero_negsign(dest, src, (width - arg_size)));
}

char	*rj_strncpy(char *src, int width)
{
	char *dest;
	size_t i;
	size_t x;
	int arg_size;

	arg_size = ft_strlen(src);
	dest = ft_strnew(width + arg_size);
	i = 0;
	x = 0;
	if (width > arg_size)
		dest = leading_zeros_spaces(dest, src, width, arg_size);
	else if (ft_atoi(src) >= 0 && CHECK_BIT(args.arg1, PLUS_F))
		dest = prependchar('+', (ft_strcpy(dest, src)));
	else
		ft_strcpy(dest, src);
	return (dest);
}

//int		main(int ac, char **av)
//{
//	//clock_t t;
//	if(ac == 3)
//	{
//		//(void)av;
//		//(void)ac;
//		int width = ft_atoi(av[2]);
//		//SET_BIT(args.arg1, ZERO_F);
//		//SET_BIT(args.arg1, PLUS_F);
//		//char src[] = "42";
//		int x = ft_atoi(av[1]);
//		printf("ft_printf:%s\n", rj_strncpy(av[1], width));
//		if (CHECK_BIT(args.arg1, ZERO_F) && CHECK_BIT(args.arg1, PLUS_F))
//			printf("printf   :%+0*d\n", width, x);
//		else if (CHECK_BIT(args.arg1, ZERO_F))
//			printf("printf   :%0*d\n", width, x);
//		else if (CHECK_BIT(args.arg1, PLUS_F))
//			printf("printf   :%+*d\n", width, x);
//		else
//			printf("printf   :%*s\n", width, aplha);
//	}
//	return (0);
//}



		//t = clock();
		//printf("ft_printf:%s\n", rj_strncpy(av[1], width));
		//t = clock() - t;
		//double time_taken = ((double)t)/CLOCKS_PER_SEC;
		//printf("ft_printf() took %f seconds to execute \n\n", time_taken);
		//t = clock();
		//if (CHECK_BIT(args.arg1, ZERO_F) && CHECK_BIT(args.arg1, PLUS_F))
		//	printf("printf   :%+0*d\n", width, x);
		//else if (CHECK_BIT(args.arg1, ZERO_F))
		//	printf("printf   :%0*d\n", width, x);
		//else if (CHECK_BIT(args.arg1, PLUS_F))
		//	printf("printf   :%+*d\n", width, x);
		//else
		//	printf("printf   :%*d\n", width, x);
		//t = clock() - t;
		//double time_taken2 = ((double)t)/CLOCKS_PER_SEC;
		//printf("libary printf() took %f seconds to execute \n", time_taken2);
