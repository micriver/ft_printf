/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/02 19:51:13 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HEADERS/ft_printf.h"
#include <stdio.h>
#include <time.h>

char	*conversion(char *str, int *i)
{
	char *result;
	char *str2;
	while (str[*i])
	{
		(str[*i] == '#') ? SET_BIT(args.arg1, SHARP_F) : str[*i];
		(str[*i] == '0') ? SET_BIT(args.arg1, ZERO_F) : str[*i];
		if (str[*i] == '0')
		{
			SET_BIT(args.arg1, ZERO_F);
			i++;
		}
		(str[*i] == '-') ? SET_BIT(args.arg1, MINUS_F) : str[*i];
		(str[*i] == '+') ? SET_BIT(args.arg1, PLUS_F) : str[*i];
		(str[*i] == ' ') ? SET_BIT(args.arg1, INVP_F) : str[*i];
		//(isdigit(str[i])) ? //have to think about if someone puts a huge number for the width in here 
		if (str[++i] == 'd')
		{
			str2 = ft_itoa(va_arg(args, int));
			str = ft_strcat(str, str2);
			//ft_strcpy(&buf[j], str);
			//j += ft_strlen(str);
		}
		result = rj_strncpy(str, 10);
	}
	return (result);
}





//#define CHECK_BIT(var,pos) ((var >> pos) & 1) 
//#define SET_BIT(var,pos) (var |= 1 << pos) 
//#define TOGGLE_BIT(var,pos) (var ^= (1 << pos)) 
