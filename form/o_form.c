/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:57:50 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/06 13:31:00 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*o_pbuild(char *temp, char *origstr)
{
	int i;
	char *temp2;

	i = 0;
	if (arg.precision >= (int)ft_strlen(origstr))
	{
		temp2 = ft_strnew(arg.precision - (int)ft_strlen(origstr));
		while (i < (arg.precision - (int)ft_strlen(origstr)))
			temp2[i++] = '0';
		temp = ft_strjoin(temp2, origstr);
		free(temp2);
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

char		*o_sharpf(char *temp, char *origstr)
{
	if (ft_strcmp(origstr, "0") == 0)
		temp = ft_strcpy(temp, origstr);
	else if ((ft_strcmp(origstr, "0") == 0) && LONEDEC_F)
		temp = ft_strcpy(temp, origstr);
	else
		PREC += ((int)ft_strlen(origstr) + 1);
	return (temp);
}

void		o_form(char *origstr)
{
	char		*temp;

	temp = ft_strnew(ft_strlen(origstr));
	if (SHARP_FLAG)
		temp = o_sharpf(temp, origstr);
	if (LONEDEC_F)
		temp = o_lonedecf(temp, origstr);
	if (PREC)
		temp = o_pbuild(temp, origstr);
	else if (EXP_0_F && !SHARP_FLAG)
		temp = o_explicitzero(temp, origstr);
	else
	{
		if (!SHARP_FLAG && LONEDEC_F && (ft_strcmp(origstr, "0") == 0))
			temp[0] = '\0';
		else
			temp = ft_strcpy(temp, origstr);
	}
	if (arg.width)
		temp = o_wbuild(temp);
	prfree(temp);
	free(origstr);
}
