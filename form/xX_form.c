/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xX_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:50:15 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 19:11:10 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*xX_pbuild(char *temp, char *origstr)
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

char		*xX_wstrbuild(char *temp)
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

char		*xX_wbuild(char *temp)
{
	if (arg.width <= (int)ft_strlen(temp))
		return (temp);
	else
		temp = xX_wstrbuild(temp);
	return (temp);
}

void		xX_zero(char *temp, char *origstr)
{
	if ((ft_strcmp(origstr, "0") == 0) && (CHECK_BIT(arg.flgmods, LONEDEC)))
	{
		temp[0] = '\0';
		prfree(temp);
	}
	else
	{
		prfree(temp);
		free(origstr);
	}
}

void		xX_form(char *origstr)
{
	char		*temp;

	temp = ft_strnew(ft_strlen(origstr));
	if (arg.precision)
	{
		temp = xX_pbuild(temp, origstr);
		if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) && arg.conv != 'X')
			temp = ft_strjoin("0x", temp);
		else if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) \
				&& arg.conv == 'X')
			temp = ft_strjoin("0X", temp);
	}
	else
	{
		temp = ft_strcpy(temp, origstr);
		if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) && arg.conv != 'X')
			temp = ft_strjoin("0x", temp);
		else if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) \
				&& arg.conv == 'X')
			temp = ft_strjoin("0X", temp);
	}
	if (arg.width)
		temp = xX_wbuild(temp);
	xX_zero(temp, origstr);
}
