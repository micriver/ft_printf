/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:55:25 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/01 16:06:36 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

//precision limits the string if the
//string length is shorter
void		s_form(char *origstr)
{
	char	*formstr;
	char	*temp;
	int		i;
	int		diff;

	i = 0;
	if (ft_strcmp(origstr, "(null)") == 0)
		temp = ft_strnew(6);
	else
		temp = ft_strnew(ft_strlen(origstr));
	//if theres a precision, build the precision string first
	if (arg.precision)
	{
		if (arg.precision > arg.width)
			arg.width = 0;
		int x;
		x = 0;
		while (x < arg.precision)
		{
			temp[x] = origstr[x];
			x++;
		}
		if (!(ft_strcmp(origstr, "(null)") == 0))
			temp[x] = '\0';
	}
	else
		temp = ft_strcpy(temp, origstr);
	formstr = NULL;
	if (arg.width)
	{
		if (CHECK_BIT(arg.flgmods, LONEDEC))
			temp = "";
		if (origstr == NULL)
			diff = arg.width - 6;
		else
			diff = arg.width - (int)ft_strlen(temp);
		formstr = ft_strnew(arg.width);
		while (i < diff)
			formstr[i++] = ' ';
		if (CHECK_BIT(arg.flgmods, MINUS_F))
			temp = ft_strjoin(temp, formstr);
		else
			temp = ft_strjoin(formstr, temp);
	}
	prfree(temp);
	free(formstr);
}
