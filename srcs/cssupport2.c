/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cssupport2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 14:23:53 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/07 20:04:21 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

/*
** The next couple functions support the check
** for the invisible plus sign flag on negative number arguments
** within the dui_sign.c file.
** There are a variety of checks arrived at
** through testing various values and combinations.
*/

char	*ippr_widch(char *formstr, char *origstr)
{
	if (origstr[0] == '-' && PREC >= (int)ft_strlen(origstr))
		origstr[0] = '0';
	if (ft_strcmp(formstr, origstr) == 0)
		;
	else
	{
		ft_srch_rep(formstr, '-', '0');
		formstr = ft_prependchar('-', formstr);
	}
	return (formstr);
}

char	*ipunder_pr(char *formstr)
{
	int i;

	i = 0;
	ft_srch_rep(formstr, '-', '0');
	if (formstr[i] == '0')
		formstr = ft_prependchar('-', formstr);
	else if (formstr[i] == '0' && (WIDTH > PREC))
		formstr = ft_insertchar(formstr, '-', 0);
	else
	{
		while (formstr[i] == ' ')
			i++;
		formstr[i - 1] = '-';
	}
	return (formstr);
}

char	*ipweird1ch(char *formstr)
{
	ft_srch_rep(formstr, '-', '0');
	formstr = ft_prependchar('-', formstr);
	return (formstr);
}

char	*ipweird2ch(char *formstr)
{
	int i;

	i = 0;
	ft_srch_rep(formstr, '-', '0');
	while (formstr[i] == ' ')
		i++;
	formstr[i - 1] = '-';
	return (formstr);
}
