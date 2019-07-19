/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/19 12:01:14 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>
#include <time.h>

char	*conversion(int *i, char *str, va_list args)
{
	char *result;
	
	master_pars(str, i);
	//majority of the work has to happen below here now
	//typecast for each length modifier happens in the actual conversion
	//specifier function/c file
	//place a while loop here where you loop through n
	//and a list of speciefers in a string
	if (str[*i] == 'd' || str[*i] == 'i')
		result = (char *)di_specifier(args);
		//result = ft_itoa(va_arg(args, int));
	else
		result = NULL; 
	return (result);
}
