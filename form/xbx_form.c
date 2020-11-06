/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xbx_form.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 22:44:06 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 15:48:12 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*xbx_pbuild(char *origstr)
{
	int		i;
	int		length;
	char	*temp2;
	char	*temp;

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
	if (LONEDEC_F)
		xbx_zeroch3(temp, origstr);
	else
	{
		if (!PREC && !WIDTH && !SHARP_FLAG)
			prfree(origstr);
		else if ((ft_strcmp(origstr, "0") == 0) && SHARP_FLAG)
		{
			prfree(origstr);
			free(temp);
		}
		else
			xbx_zeroch2(temp, origstr);
	}
}

void		xbx_form(char *origstr)
{
	char		*temp;
	char		*temp2;

	temp = NULL;
	temp2 = NULL;
	if (arg.precision)
		temp = xbx_prch(origstr, temp, temp2);
	else
		temp = bx_zeroch(temp, origstr);
	if (arg.width)
	{
		if (!PREC && !SHARP_FLAG)
			temp = ft_strdup(origstr);
		temp2 = xbx_wbuild(temp);
		xbx_zero(temp2, origstr);
	}
	else
		xbx_nowid(temp, origstr, temp2);
}
