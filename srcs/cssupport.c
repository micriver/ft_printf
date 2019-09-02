/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cssupport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:04:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 14:39:06 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

/*
** The next couple functions support the check
** for the plus sign flag on negative number arguments
** within the dui_sign.c file.
** There are a variety of checks arrived at
** through testing various values and combinations.
*/

char	*pr_widch(char *formstr, char *origstr)
{
	if (origstr[0] == '-' && PREC >= (int)ft_strlen(origstr))
		origstr[0] = '0';
	if (ft_strcmp(formstr, origstr) == 0)
		;
	else
	{
		formstr = ft_srch_rep(formstr, '-', '0');
		formstr = ft_prependchar('-', formstr);
	}
	return (formstr);
}

char	*under_pr(char *formstr)
{
	int i;

	i = 0;
	formstr = ft_srch_rep(formstr, '-', '0');
	if (formstr[i] == '0' && (WIDTH < PREC))
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

char	*weird1ch(char *formstr)
{
	formstr = ft_srch_rep(formstr, '-', '0');
	formstr = ft_prependchar('-', formstr);
	return (formstr);
}

char	*weird2ch(char *formstr)
{
	int i;

	i = 0;
	formstr = ft_srch_rep(formstr, '-', '0');
	while (formstr[i] == ' ')
		i++;
	formstr[i - 1] = '-';
	return (formstr);
}