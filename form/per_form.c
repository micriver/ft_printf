/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   per_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 15:15:42 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/05 13:38:54 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*per_ljstr(char orig, char *formstr)
{
	int i;

	i = 0;
	formstr = ft_strnew(arg.width);
	formstr[i] = orig;
	while (++i < arg.width)
		formstr[i] = ' ';
	formstr[i] = '\0';
	return (formstr);
}

char	*per_form(char orig)
{
	char	*formstr;
	int		i;

	i = 0;
	formstr = NULL;
	if (CHECK_BIT(arg.flgmods, MINUS_F))
		formstr = per_ljstr(orig, formstr);
	else
	{
		formstr = ft_strnew(arg.width);
		while (i < arg.width)
		{
			formstr[i] = ' ';
			if (ZERO_FLAG)
				formstr[i] = '0';
			i++;
		}
		formstr[i - 1] = orig;
		formstr[i] = '\0';
	}
	return (formstr);
	free(formstr);
}
