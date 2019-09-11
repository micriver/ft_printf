/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xbx_form2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:35:11 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 16:03:16 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		xbx_nowid(char *temp, char *origstr, char *temp2)
{
	if (!SHARP_FLAG && PREC)
	{
		free(temp);
		temp = origstr;
		if (!WIDTH)
			free(temp2);
	}
	xbx_zero(temp, origstr);
}

char		*bx_zeroch(char *temp, char *origstr)
{
	if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) && arg.conv != 'X')
		temp = ft_strjoin("0x", origstr);
	else if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) \
			&& arg.conv == 'X')
		temp = ft_strjoin("0X", origstr);
	return (temp);
}

int			ft_free(void *data)
{
	free(data);
	return (1);
}

char		*xbx_prch(char *origstr, char *temp, char *temp2)
{
	temp = xbx_pbuild(origstr);
	if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) && arg.conv != 'X')
	{
		temp2 = temp;
		(temp = ft_strjoin("0x", temp)) && ft_free(temp2);
	}
	else if ((SHARP_FLAG) && (ft_strcmp(origstr, "0") != 0) \
			&& arg.conv == 'X')
	{
		temp2 = temp;
		(temp = ft_strjoin("0X", temp)) && ft_free(temp2);
	}
	else if (!(ZERO_FLAG) && (int)ft_strlen(origstr) <= PREC)
		free(temp2);
	return (temp);
}
