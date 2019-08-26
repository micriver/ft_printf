/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/25 14:21:37 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/25 16:47:47 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

//create the rounding function first
long double		ft_round(long double value)
{
	long double result;
	int multip;
	int i;
	
	i = 1;
	multip = 1;
	while (i <= 2)
	//while (i <= arg.prec)
	{
		multip *= 10;
		i++;
	}
	result = (int)(value * multip) + .5;
	return (printf ("%.7f\n", (float)result / multip));
	//return ((float)result / multip);
}

#if 1

int		main()
{
	//float value = -37.66666;
	//float value = -10.000;
	//float value = -23.688;
	//float value = -11029.000568;
	//float value = -11029.8641;
	float value = -12229.12436800;
	ft_round(value);
}


#endif
//
//then create the f_itoa
