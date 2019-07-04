/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/03 19:44:46 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./HEADERS/ft_printf.h"
#include <stdio.h>
#include <time.h>

char	*conversion(int *i, va_list(char *str, va_list args))
{
	char *result;
	char *str2;
	while (str[*i])
	{
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
