/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/05 18:45:42 by mirivera         ###   ########.fr       */
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
	{'o', o_conv},
	{'p', p_conv},
	{'x', xbx_conv},
	{'X', xbx_conv},
	{'%', specconversion}
};

void	conversion(int *i, char *str, va_list args)
{
	size_t x;

	x = 0;
	(*i)++;
	master_pars(str, i);
	while (x < ft_strlen(CONV_SPECS))
	{
		if (g_dt[x].specifier == arg.conv)
		{
			g_dt[x].function(args);
			break ;
		}
		x++;
	}
}
