/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:51:48 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 11:30:11 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*neg_plusch(char *formstr, char *origstr)
{
	int i;

	i = 0;
	if (PREC == WIDTH)
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
	}
	else if ((int)ft_strlen(origstr) < PREC)
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
	else if (origstr[0] == '-' && (PREC > ((int)ft_strlen(origstr) - 1)) \
			&& !(WIDTH > PREC))
	{
		formstr = ft_srch_rep(formstr, '-', '0');
		formstr = ft_prependchar('-', formstr);
	}
	else if (origstr[0] == '-' && (PREC > ((int)ft_strlen(origstr) - 1)) \
			&& WIDTH > PREC)
	{
		formstr = ft_srch_rep(formstr, '-', '0');
		while (formstr[i] == ' ')
			i++;
		formstr[i - 1] = '-';
	}
	else
	{
		while (formstr[i] == ' ' || formstr[i] == '-')
			i++;
		formstr[i - 1] = '-';
	}
	return (formstr);
}

char	*pos_plusch(char *formstr, char *origstr)
{
	int i;

	i = 0;
	if ((CHECK_BIT(arg.flgmods, PLUS_F)) && (origstr[0] != '-') && \
			(!CHECK_BIT(arg.flgmods, ZERO_F)))
	{
		if (PREC >= WIDTH)
			formstr = ft_prependchar('+', formstr);
		else if ((CHECK_BIT(arg.flgmods, PLUS_F)) && \
				(CHECK_BIT(arg.flgmods, MINUS_F)) && (ft_atoi(origstr) >= 0))
			formstr = ft_insertchar(formstr, '+', 0);
		else
		{
			while (formstr[i] == ' ')
				i++;
			formstr[i - 1] = '+';
		}
	}
	return (formstr);
}

/*
** This function checks for the plus flag
** Then looks at the original converted argument string
** to find out if it's a negative or positive number.
** Depending on the result, it calls the functions to
** the signs to the string
*/

char	*plusf_check(char *formstr, char *origstr)
{
	int i;

	i = 0;
	if ((CHECK_BIT(arg.flgmods, PLUS_F)) && (origstr[0] != '-') && \
			(!CHECK_BIT(arg.flgmods, ZERO_F)))
		formstr = pos_plusch(formstr, origstr);
	if ((CHECK_BIT(arg.flgmods, PLUS_F)) && (origstr[0] == '-') && \
			(!CHECK_BIT(arg.flgmods, ZERO_F)))
		formstr = neg_plusch(formstr, origstr);
	return (formstr);
}

/*
** dui_sign takes the formatted string, the original
** converted argument string and checks for flags
** that alter the final string. The function calls
** prepend/prefix the formatted string for output
*/

void	dui_sign(char *formstr, char *origstr)
{
	formstr = plusf_check(formstr, origstr);
	prfree(formstr);
	free(origstr);
}
