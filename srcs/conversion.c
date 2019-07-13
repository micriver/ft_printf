/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/12 19:00:55 by mirivera         ###   ########.fr       */
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
	if (str[*i] == 'd')
	{
		result = ft_itoa(va_arg(args, int));
		//rj_strncpy goes here
		result = rj_strncpy(result);
	}
	else
		result = NULL; 
	return (result);
}
