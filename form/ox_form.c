/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ox_form.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:17:03 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 16:29:51 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*ox_pbuild(char *temp, char *origstr)
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

char		*ox_wstrbuild(char *temp)
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

char		*ox_wbuild(char *temp)
{
	if (arg.width <= (int)ft_strlen(temp))
		return (temp);
	else
		temp = ox_wstrbuild(temp);
	return (temp);
}

void		ox_form(char *origstr)
{
	char	*temp;

	temp = ft_strnew(ft_strlen(origstr));
	if (arg.precision)
		temp = ox_pbuild(temp, origstr);
	else
		temp = ft_strcpy(temp, origstr);
	if (arg.width)
		temp = ox_wbuild(temp);
	if (SHARP_FLAG && (!(ft_strcmp(origstr, "4dc") == 0)))
		ft_strjoin("0x", temp);
	prfree(temp);
	free(origstr);
}
