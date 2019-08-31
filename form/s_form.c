/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:55:25 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/31 14:10:34 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		s_form(char *origstr)
{
	char	*formstr;
	int		i;
	int		diff;

	i = 0;
	if (origstr == NULL)
		diff = arg.width - 6;
	else
		diff = arg.width - (int)ft_strlen(origstr);
	if (CHECK_BIT(arg.flgmods, MINUS_F))
	{
		formstr = ft_strnew(arg.width);
		while (i < diff)
			formstr[i++] = ' ';
		formstr = ft_strjoin(origstr, formstr);
	}
	else
	{
		formstr = ft_strnew(arg.width);
		while (i < diff)
			formstr[i++] = ' ';
		formstr = ft_strjoin(formstr, origstr);
	}
	prfree(formstr);
}
