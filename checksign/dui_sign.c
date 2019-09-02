/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:51:48 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/01 20:59:20 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	dui_sign(char *formstr, char *origstr)
{
	int i;

	i = 0;
	//This line makes sure the original string isn't negative
	//and adds a plus sign to the front of the number inside the string
	if ((CHECK_BIT(arg.flgmods, PLUS_F)) && (origstr[0] != '-') && \
			(!CHECK_BIT(arg.flgmods, ZERO_F)))
	{
		if (arg.precision >= arg.width)
			formstr = ft_prependchar('+', formstr);
		else
		{
			while (formstr[i] == ' ')
				i++;
			formstr[i - 1] = '+';
		}
	}
	//This line checks for plus signs and makes sure the original string
	//is a negative number
	else if ((CHECK_BIT(arg.flgmods, PLUS_F)) && (origstr[0] == '-') && \
			(!CHECK_BIT(arg.flgmods, ZERO_F)))
	{
		//next two lines check for strings are longer than
		//their precision and are negative for sign placement
		if (arg.precision == arg.width)
		{
			if (origstr[0] == '-' && arg.precision >= (int)ft_strlen(origstr))
				origstr[0] = '0';
			if (ft_strcmp(formstr, origstr) == 0)
				;
			else
			{
				formstr = ft_srch_rep(formstr, '-', '0');
				formstr = ft_prependchar('-', formstr);
			}
		}
		else if ((int)ft_strlen(origstr) < arg.precision)
		{
			formstr = ft_srch_rep(formstr, '-', '0');
			if (formstr[i] == '0')
				formstr = ft_prependchar('-', formstr);
			else
			{
				while (formstr[i] == ' ')
					i++;
				formstr[i - 1] = '-';
			}
		}
		else if (origstr[0] == '-' && (arg.precision > ((int)ft_strlen(origstr) - 1)))
		{
			formstr = ft_srch_rep(formstr, '-', '0');
			formstr = ft_prependchar('-', formstr);
		}
		else
		{
			while (formstr[i] == ' ' || formstr[i] == '-')
				i++;
			formstr[i - 1] = '-';
		}
	}
	prfree(formstr);
	free(origstr);
}
