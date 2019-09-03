/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plusf_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:26:39 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 19:43:25 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*neg_plusch(char *formstr, char *origstr)
{
	int i;

	i = 0;
	if (PREC == WIDTH)
		formstr = pr_widch(formstr, origstr);
	else if ((int)ft_strlen(origstr) < PREC)
		formstr = under_pr(formstr);
	else if (origstr[0] == '-' && (PREC > ((int)ft_strlen(origstr) - 1)) \
			&& !(WIDTH > PREC))
		formstr = weird1ch(formstr);
	else if (origstr[0] == '-' && (PREC > ((int)ft_strlen(origstr) - 1)) \
			&& WIDTH > PREC)
		formstr = weird2ch(formstr);
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
	if ((PLUS_FLAG) && (origstr[0] != '-') && \
			(!ZERO_FLAG))
	{
		if (PREC >= WIDTH)
			formstr = ft_prependchar('+', formstr);
		else if ((PLUS_FLAG) && \
				(MINUS_FLAG) && (ft_atoi(origstr) >= 0))
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
	if ((PLUS_FLAG) && (origstr[0] != '-') && \
			(!ZERO_FLAG))
		formstr = pos_plusch(formstr, origstr);
	else if ((PLUS_FLAG) && (origstr[0] != '-') && \
			(ZERO_FLAG))
		formstr = ft_prefixchar('+', formstr);
	if ((PLUS_FLAG) && (origstr[0] == '-') && \
			(!ZERO_FLAG))
		formstr = neg_plusch(formstr, origstr);
	return (formstr);
}
