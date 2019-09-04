/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:15:42 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/04 15:23:38 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*per_form(char orig)
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
