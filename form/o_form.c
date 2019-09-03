/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:57:50 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 22:39:44 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*o_pbuild(char *temp, char *origstr)
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

char		*o_wstrbuild(char *temp)
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

char		*o_wbuild(char *temp)
{
	if (arg.width <= (int)ft_strlen(temp))
		return (temp);
	else
		temp = o_wstrbuild(temp);
	return (temp);
}

char		*o_zeroch(char *temp, char *origstr)
{
	if (PREC == 0)
		PREC = -1;
	temp = ft_strcpy(temp, origstr);
	if (SHARP_FLAG)
	{
		if (LONEDEC_F)
			temp = ft_strcpy(temp, origstr);
		else if (PREC == 0)
			temp = ft_strcpy(temp, origstr);
	}
	else if (LONEDEC_F)
		temp[0] = '\0';
	else
		temp = ft_strcpy(temp, origstr);
	return (temp);
}

void		o_form(char *origstr)
{
	char		*temp;

	temp = ft_strnew(ft_strlen(origstr));
	if (SHARP_FLAG && (ft_strcmp(origstr, "0") != 0))
		PREC += (ft_strlen(origstr) + 1);
	if (ft_strcmp(origstr, "0") == 0)
		temp = o_zeroch(temp, origstr);
	else
	{
		if (PREC)
			temp = o_pbuild(temp, origstr);
		else
			temp = ft_strcpy(temp, origstr);
	}
	if (arg.width)
		temp = o_wbuild(temp);
	prfree(temp);
	free(origstr);
}
