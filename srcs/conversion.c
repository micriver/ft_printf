/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/30 14:28:04 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>
#include <time.h>

char	*conversion(int *i, char *str, va_list args)
{
	char *result;
	//int64_t di;

	master_pars(str, i);
	//majority of the work has to happen below here now
	
	//place a while loop here where you loop through n
	
	//and a list of specifiers in a string
	//while loop and dispatch table here
	if (str[*i] == 'd' || str[*i] == 'i' )
	{
		int64_t di; //this needs to be able to hold at least 64 bits
					//for whatever value comes back from di_return value
		di = di_return_value(args);
		result = di_specifier(di);
	}
	else if (str[*i] == 'u')
	{
		int64_t u;
		u = u_return_value(args);
		result = u_specifier(u);
	}
	else if (str[*i] == 's')
		result = s_specifier(args);
	else
		result = NULL; 
	return (result);
}

