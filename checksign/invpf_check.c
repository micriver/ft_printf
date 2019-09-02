/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   invsf_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 13:30:49 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 13:40:01 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*pos_invpch(char *formstr, char *origstr)
{
	int i;

	i = 0;
	if ((INVP_FLAG) && (origstr[0] != '-') && \
			(!ZERO_FLAG))
	{
		if (PREC >= WIDTH)
			formstr = ft_prependchar('+', formstr);
		else if ((INVP_FLAG) && \
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

char	*invpf_check(char *formstr, char *origstr)
{
	if ((INVP_FLAG) && (origstr[0] != '-') && \
			(!ZERO_FLAG))
		formstr = pos_invpch(formstr, origstr);
	//if ((INVP_FLAG) && (origstr[0] == '-') && \
	//		(!ZERO_FLAG))
	//	formstr = neg_plusch(formstr, origstr);
	return (formstr);
}
