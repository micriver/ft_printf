/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:19:12 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/04 15:17:41 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*c_form(char orig)
{
	char	*formstr;
	int		i;

	i = 0;
	if (CHECK_BIT(arg.flgmods, MINUS_F))
	{
		formstr = ft_strnew(arg.width);
		formstr[i] = orig;
		while (++i < arg.width)
			formstr[i] = ' ';
		formstr[i] = '\0';
	}
	else
	{
		formstr = ft_strnew(arg.width);
		while (i < arg.width)
			formstr[i++] = ' ';
		formstr[i - 1] = orig;
		formstr[i] = '\0';
	}
	return (formstr);
	free(formstr);
}
