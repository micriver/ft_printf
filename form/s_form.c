/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:55:25 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/01 16:48:19 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*s_pbuild(char *temp, char *origstr)
{
	int x;

	x = 0;
	if (arg.precision > arg.width)
		arg.width = 0;
	while (x < arg.precision)
	{
		temp[x] = origstr[x];
		x++;
	}
	if (!(ft_strcmp(origstr, "(null)") == 0))
		temp[x] = '\0';
	return (temp);
}

char		*s_wbuild(char *temp, char *origstr)
{
	char	*formstr;
	int		i;
	int		diff;

	i = 0;
	formstr = ft_strnew(arg.width);
	if (CHECK_BIT(arg.flgmods, LONEDEC))
		temp = "";
	if (origstr == NULL)
		diff = arg.width - 6;
	else
		diff = arg.width - (int)ft_strlen(temp);
	if (arg.width < (int)ft_strlen(temp))
		temp = ft_strcpy(temp, origstr);
	else
	{
		while (i < diff)
			formstr[i++] = ' ';
		if (CHECK_BIT(arg.flgmods, MINUS_F))
			temp = ft_strjoin(temp, formstr);
		else
			temp = ft_strjoin(formstr, temp);
	}
	free(formstr);
	return (temp);
}

void		s_form(char *origstr)
{
	char	*temp;

	if (ft_strcmp(origstr, "(null)") == 0)
		temp = ft_strnew(6);
	else
		temp = ft_strnew(ft_strlen(origstr));
	if (arg.precision)
		temp = s_pbuild(temp, origstr);
	else
		temp = ft_strcpy(temp, origstr);
	if (arg.width)
		temp = s_wbuild(temp, origstr);
	prfree(temp);
}
