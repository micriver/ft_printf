/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:05:31 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/31 14:26:50 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		p_form(char *orig)
{
	char	*formstr;
	int		i;
	int		diff;

	i = 0;
	if (arg.width)
		diff = arg.width - (int)ft_strlen(orig);
	if (CHECK_BIT(arg.flgmods, MINUS_F))
	{
		formstr = ft_strnew(arg.width);
		while (i < diff)
			formstr[i++] = ' ';
		formstr = ft_strjoin(orig, formstr);
	}
	else
	{
		formstr = ft_strnew(arg.width);
		while (i < diff)
			formstr[i++] = ' ';
		formstr = ft_strjoin(formstr, orig);
	}
	prfree(formstr);
}
