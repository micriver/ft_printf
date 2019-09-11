/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invsf_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:30:49 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 16:41:02 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*neg_invpch(char *formstr, char *origstr)
{
	int i;

	i = 0;
	if (PREC == WIDTH)
		formstr = ippr_widch(formstr, origstr);
	else if ((int)ft_strlen(origstr) < PREC)
		formstr = ipunder_pr(formstr);
	else if (origstr[0] == '-' && (PREC > ((int)ft_strlen(origstr) - 1)) \
			&& !(WIDTH > PREC))
		formstr = ipweird1ch(formstr);
	else if (origstr[0] == '-' && (PREC > ((int)ft_strlen(origstr) - 1)) \
			&& WIDTH > PREC)
		formstr = ipweird2ch(formstr);
	else
	{
		while (formstr[i] == ' ' || formstr[i] == '-')
			i++;
		formstr[i - 1] = '-';
	}
	return (formstr);
}

char	*zero_flch(char *formstr, char *origstr)
{
	int		i;
	char	*result;

	i = 0;
	if (PREC >= WIDTH)
	{
		result = ft_prependchar(' ', formstr);
		free(formstr);
		return (result);
	}
	else if ((INVP_FLAG) && \
			(MINUS_FLAG) && (ft_atoi(origstr) >= 0))
	{
		result = ft_insertchar(formstr, ' ', 0);
		free(formstr);
		return (result);
	}
	else
	{
		while (formstr[i] == ' ')
			i++;
		formstr[i - 1] = ' ';
	}
	return (formstr);
}

char	*pos_invpch(char *formstr, char *origstr)
{
	char	*result;

	if ((INVP_FLAG) && (origstr[0] != '-') && \
			(!ZERO_FLAG))
	{
		result = zero_flch(formstr, origstr);
		return (result);
	}
	else if ((INVP_FLAG) && (origstr[0] != '-') && \
			(ZERO_FLAG))
		ft_prefixchar(' ', formstr);
	return (formstr);
}

char	*invpf_check(char *formstr, char *origstr)
{
	char	*result;

	if ((INVP_FLAG) && (origstr[0] != '-'))
		result = pos_invpch(formstr, origstr);
	else if ((INVP_FLAG) && (origstr[0] == '-') && \
			(!ZERO_FLAG))
		result = neg_invpch(formstr, origstr);
	else
		result = ft_strdup(formstr);
	return (result);
}
