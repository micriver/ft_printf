/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xbx_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:44:06 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/09 11:31:28 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*xbx_pbuild(char *origstr)
{
	int i;
	int length;
	char *temp2;
	char *temp;

	i = 0;
	length = arg.precision - (int)ft_strlen(origstr);
	if (arg.precision >= (int)ft_strlen(origstr))
	{
		temp2 = ft_strnew(length);
		while (i < (length))
			temp2[i++] = '0';
		temp = ft_strjoin(temp2, origstr);
		free(temp2);
	}
	else
		temp = ft_strdup(origstr);
	return (temp);
}

char		*xbx_wstrbuild(char *temp)
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

char		*xbx_wbuild(char *temp)
{
	char *temp2;

	if (arg.width <= (int)ft_strlen(temp))
		return (temp);
	else
	{
		temp2 = temp;
		temp = xbx_wstrbuild(temp2);
		free(temp2);
	}
	return (temp);
}

void		xbx_zero(char *temp, char *origstr)
{
	if ((ft_strcmp(temp, "0") == 0) && (CHECK_BIT(arg.flgmods, LONEDEC)))
	{
		temp[0] = '\0';
		prfree(temp);
	}
	else
	{
		if (!PREC && !WIDTH && !SHARP_FLAG)
			prfree(origstr);
		else
		{
			if (SHARP_FLAG)
				free(origstr);
			prfree(temp);
		}
	}
}

int			ft_free(void *data)
{
	free(data);
	return (1);
}

void		xbx_form(char *origstr)
{
	char		*temp;
	char		*temp2;

	if (arg.precision)
	{
		temp = xbx_pbuild(origstr);
		temp2 = temp;
		if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) && arg.conv != 'X')
			(temp = ft_strjoin("0x", temp)) && ft_free(temp2);
		else if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) \
				&& arg.conv == 'X')
			(temp = ft_strjoin("0X", temp)) && ft_free(temp2);
	}
	else
	{
		if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) && arg.conv != 'X')
			temp = ft_strjoin("0x", origstr);
		else if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) \
				&& arg.conv == 'X')
			temp = ft_strjoin("0X", origstr);
	}
	if (arg.width)
	{
		temp = xbx_wbuild(origstr);
		xbx_zero(temp, origstr);
	}
	else
	{
		if (!SHARP_FLAG)
			temp = origstr;
		xbx_zero(temp, origstr);
	}
}
