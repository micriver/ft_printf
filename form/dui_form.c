/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/01 17:40:14 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/07 21:45:57 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

char		*dui_pbuild(char *origstr)
{
	int i;
	int length;
	char *temp;
	char *temp2;

	i = 0;
	length = PREC - (int)ft_strlen(origstr);
	temp2 = ft_strnew(length);
	while (i < (length))
		temp2[i++] = '0';
	temp = ft_strjoin(temp2, origstr);
	free(temp2);
	return (temp);
}

char		*wbuild(char *temp)
{
	int		diff;
	int		i;
	char	*formstr;
	char	*result;

	i = 0;
	diff = WIDTH - (int)ft_strlen(temp);
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
	{
		result = ft_strjoin(temp, formstr);
		(ft_strcmp("", temp) == 0) ? temp : free(temp);
	}
	else
	{
		result = ft_strjoin(formstr, temp);
		(ft_strcmp("", temp) == 0) ? temp : free(temp);
	}
	free(formstr);
	return (result);
}

char		*dui_wbuild(char *temp)
{
	char *result;

	if (arg.width <= (int)ft_strlen(temp))
	{
		result = temp;
		return (result);
	}
	else
	{
		result = wbuild(temp);
		//free(temp);
	}
	return (result);
}

void		dui_form(char *origstr)
{
	char	*temp;
	char	*temp2;

	if ((ft_strcmp(origstr, "0") == 0) && (LONEDEC_F))
		temp = "";
	else if (arg.precision)
	{
		if (PREC > (int)ft_strlen(origstr))
		{
			temp = dui_pbuild(origstr);
			//free(temp2);
		}
		else
			temp = ft_strdup(origstr);
	}
	else
		temp = ft_strdup(origstr);
	if (arg.width)
	{
		temp2 = dui_wbuild(temp);
		//free(temp);
		dui_sign(temp2, origstr);
	}
	else
		dui_sign(temp, origstr);
}
