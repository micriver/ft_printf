/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:51:48 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/09 10:32:55 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

/*
** dui_sign takes the formatted string, the original
** converted argument string and checks for flags
** that alter the final string. The function calls
** prepend/prefix the formatted string for output
*/

void	dui_sign(char *formstr, char *origstr)
{
	char *result;

	if (PLUS_FLAG)
	{
		result = plusf_check(formstr, origstr);
		prfree(result);
		free(origstr);
	}
	else if (INVP_FLAG)
	{
		result = invpf_check(formstr, origstr);
		prfree(result);
		free(origstr);
	}
	else
	{
		prfree(formstr);
		free(origstr);
	}
	//if (!(ft_strcmp(origstr, "0") == 0) && (CHECK_BIT(arg.flgmods, LONEDEC)))
	//	free(origstr);
}
