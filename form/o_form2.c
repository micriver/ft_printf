/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_form2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 16:12:36 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 16:22:14 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void			o_ifminus(char *temp, char *origstr)
{
	if (PREC)
		o_pbuild(temp, origstr);
	if (arg.width)
	{
		if (WIDTH >= PREC)
		{
			if (arg.width >= (PREC - (int)ft_strlen(origstr)))
				o_wstrbuild(origstr);
		}
	}
	else if (!WIDTH && !PREC && !(ft_strcmp(origstr, "0") == 0))
		arg.char_count += ft_intputstr(origstr);
}

void			o_nominus(char *temp, char *origstr)
{
	if (arg.width)
	{
		if (WIDTH >= PREC)
		{
			if (arg.width >= (PREC - (int)ft_strlen(origstr)))
				o_wstrbuild(origstr);
		}
	}
	else if (PREC)
		o_pbuild(temp, origstr);
	else if ((!WIDTH && !PREC) && !(ft_strcmp(origstr, "0") == 0))
		arg.char_count += ft_intputstr(origstr);
}
