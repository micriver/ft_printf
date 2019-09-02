/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_sign.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 18:51:48 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 13:32:56 by mirivera         ###   ########.fr       */
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
	formstr = plusf_check(formstr, origstr);
	formstr = invpf_check(formstr, origstr);
	prfree(formstr);
	free(origstr);
}
