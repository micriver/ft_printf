/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invsf_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:30:49 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/07 20:15:06 by mirivera         ###   ########.fr       */
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

char	*pos_invpch(char *formstr, char *origstr)
{
	int i;

	i = 0;
	if ((INVP_FLAG) && (origstr[0] != '-') && \
			(!ZERO_FLAG))
	{
		if (PREC >= WIDTH)
			formstr = ft_prependchar(' ', formstr);
		else if ((INVP_FLAG) && \
				(MINUS_FLAG) && (ft_atoi(origstr) >= 0))
			formstr = ft_insertchar(formstr, ' ', 0);
		else
		{
			while (formstr[i] == ' ')
				i++;
			formstr[i - 1] = ' ';
		}
	}
	else if ((INVP_FLAG) && (origstr[0] != '-') && \
			(ZERO_FLAG))
		ft_prefixchar(' ', formstr);
	return (formstr);
}

char	*invpf_check(char *formstr, char *origstr)
{
	if ((INVP_FLAG) && (origstr[0] != '-'))
		pos_invpch(formstr, origstr);
	if ((INVP_FLAG) && (origstr[0] == '-') && \
			(!ZERO_FLAG))
		formstr = neg_invpch(formstr, origstr);
	//if ((INVP_FLAG) && (origstr[0] != '-'))
	//	formstr = pos_invpch(formstr, origstr);
	//if ((INVP_FLAG) && (origstr[0] == '-') && \
	//		(!ZERO_FLAG))
	//	formstr = neg_invpch(formstr, origstr);
	return (formstr);
}
