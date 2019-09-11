/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cssupport.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:04:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 13:09:39 by mirivera         ###   ########.fr       */
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
	char *result;

	if (origstr[0] == '-' && PREC >= (int)ft_strlen(origstr))
	{
		ft_srch_rep(formstr, '-', '0');
		result = ft_prependchar('-', formstr);
		free(formstr);
		return (result);
	}
	if (ft_strcmp(formstr, origstr) == 0)
		;
	else
	{
		ft_srch_rep(formstr, '-', '0');
		result = ft_prependchar('-', formstr);
		return (result);
	}
	return (formstr);
}

char	*under_pr(char *formstr)
{
	int		i;
	char	*result;

	i = 0;
	ft_srch_rep(formstr, '-', '0');
	if (formstr[i] == '0' && (WIDTH < PREC))
	{
		result = ft_prependchar('-', formstr);
		free(formstr);
	}
	else if (formstr[i] == '0' && (WIDTH > PREC))
	{
		result = ft_insertchar(formstr, '-', 0);
		free(formstr);
	}
	else
	{
		while (formstr[i] == ' ')
			i++;
		formstr[i - 1] = '-';
		result = formstr;
	}
	return (result);
}

char	*weird1ch(char *formstr)
{
	char *temp;

	temp = formstr;
	ft_srch_rep(temp, '-', '0');
	formstr = ft_prependchar('-', temp);
	free(temp);
	return (formstr);
}

char	*weird2ch(char *formstr)
{
	int i;

	i = 0;
	ft_srch_rep(formstr, '-', '0');
	while (formstr[i] == ' ')
		i++;
	formstr[i - 1] = '-';
	return (formstr);
}
