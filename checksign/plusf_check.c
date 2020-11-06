/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plusf_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:26:39 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 16:26:49 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*neg_plusch(char *formstr, char *origstr)
{
	char	*result;
	int		i;

	i = 0;
	if (PREC == WIDTH)
		result = pr_widch(formstr, origstr);
	else if ((int)ft_strlen(origstr) < PREC)
		result = under_pr(formstr);
	else if (origstr[0] == '-' && (PREC > ((int)ft_strlen(origstr) - 1)) \
			&& !(WIDTH > PREC))
		result = weird1ch(formstr);
	else if (origstr[0] == '-' && (PREC > ((int)ft_strlen(origstr) - 1)) \
			&& WIDTH > PREC)
		result = weird2ch(formstr);
	else
	{
		while (formstr[i] == ' ' || formstr[i] == '-')
			i++;
		formstr[i - 1] = '-';
		result = formstr;
	}
	return (result);
}

char	*pos_plusch(char *formstr, char *origstr)
{
	char	*result;
	int		i;

	i = 0;
	if (PREC >= WIDTH)
	{
		result = ft_prependchar('+', formstr);
		free(formstr);
	}
	else if ((PLUS_FLAG) && \
			(MINUS_FLAG) && (ft_atoi(origstr) >= 0))
	{
		result = ft_insertchar(formstr, '+', 0);
		free(formstr);
	}
	else
	{
		while (formstr[i] == ' ')
			i++;
		formstr[i - 1] = '+';
		result = formstr;
	}
	return (result);
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
	char *result;

	if ((PLUS_FLAG) && (origstr[0] != '-') && \
			(!ZERO_FLAG))
		result = pos_plusch(formstr, origstr);
	else if ((PLUS_FLAG) && (origstr[0] != '-') && \
			(ZERO_FLAG))
	{
		ft_prefixchar('+', formstr);
		result = formstr;
	}
	if ((PLUS_FLAG) && (origstr[0] == '-') && \
			(!ZERO_FLAG))
		result = neg_plusch(formstr, origstr);
	return (result);
}
