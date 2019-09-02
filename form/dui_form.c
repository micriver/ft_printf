/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:40:14 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/01 20:49:30 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*dui_pbuild(char *temp, char *origstr)
{
	int i;
	int length;

	i = 0;
	length = arg.precision - (int)ft_strlen(origstr);
	if (arg.precision >= (int)ft_strlen(origstr))
	{
		temp = ft_strnew(length);
		while (i < (length))
			temp[i++] = '0';
		temp = ft_strjoin(temp, origstr);
	}
	else
		temp = ft_strcpy(temp, origstr);
	return (temp);
}

char		*wbuild(char *temp)
{
	int		diff;
	int		i;
	char	*formstr;

	i = 0;
	diff = arg.width - (int)ft_strlen(temp);
	formstr = ft_strnew(diff);
	while (i < diff)
	{
		formstr[i] = ' ';
		(CHECK_BIT(arg.flgmods, ZERO_F) && !arg.precision) ? \
			formstr[i] = '0' : formstr[i];
		i++;
	}
	formstr[diff] = '\0';
	if (CHECK_BIT(arg.flgmods, MINUS_F))
		temp = ft_strjoin(temp, formstr);
	else
		temp = ft_strjoin(formstr, temp);
	free(formstr);
	return (temp);
}

char		*dui_wbuild(char *temp)
{
	if (arg.width <= (int)ft_strlen(temp))
		return (temp);
	else
		temp = wbuild(temp);
	return (temp);
}

void		dui_form(char *origstr)
{
	char	*temp;

	temp = ft_strnew(ft_strlen(origstr));
	if (arg.precision)
		temp = dui_pbuild(temp, origstr);
	else
		temp = ft_strcpy(temp, origstr);
	if (arg.width)
		temp = dui_wbuild(temp);
	dui_sign(temp, origstr);
}
