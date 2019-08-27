/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/27 14:19:13 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

const		t_dt	g_dt[] =
{
	{'c', c_conv},
	{'s', s_conv},
	{'d', dui_conv},
	{'u', dui_conv},
	{'i', dui_conv},
	{'f', f_conv},
	{'o', ox_conv},
	{'p', p_conv},
	{'x', ox_conv},
	{'X', bx_conv}
};

void	conversion(int *i, char *str, va_list args)
{
	int x;

	x = 0;
	(*i)++;
	master_pars(str, i);
	//see if you can insert you're conversion character macro here
	while (x < 10)
	{
		if (g_dt[x].specifier == arg.conv)
		{
			g_dt[x].function(args);
			break ;
	}
		x++;
	}
}
