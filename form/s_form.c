/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:55:25 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/30 00:18:21 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char				*s_form(char *orig);
{
	char	*formstr;
	int		i;
	int		diff;

	i = 0;
	diff = arg.width - (int)ft_strlen(orig);
	if (ft_strlen(orig) > arg.width)
		return (orig);
	if (CHECK_BIT(arg.flgmods, MINUS_F))
	{
		formstr = ft_strnew(arg.width);
		while (i < (diff)
			formstr[i++] = ' ';
		formstr = ft_strjoin(orig, formstr);
	}
	else
	{
		formstr = ft_strnew(arg.width);
		while (i < (diff)
			formstr[i++] = ' ';
		formstr = ft_strjoin(formstr, orig);
	}
	return (formstr);
	free(formstr);
}
