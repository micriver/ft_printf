/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:55:25 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/07 10:54:41 by mirivera         ###   ########.fr       */
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
	char	*temp2;
	int		i;
	int		diff;

	i = 0;
	formstr = ft_strnew(arg.width);
	if (CHECK_BIT(arg.flgmods, LONEDEC))
		temp = "";
	if (origstr == NULL)
		diff = arg.width - 6;
	else if (arg.width >= (int)ft_strlen(temp))
		diff = arg.width - (int)ft_strlen(temp);
	temp2 = temp;
	if (arg.width < (int)ft_strlen(temp))
	{
		temp = ft_strcpy(temp2, origstr);
		free(formstr);
		return (temp);
	}
	else
	{
		while (i < diff)
			formstr[i++] = ' ';
		if (CHECK_BIT(arg.flgmods, MINUS_F))
			temp = ft_strjoin(temp2, formstr);
		else
			temp = ft_strjoin(formstr, temp2);
	}
	free(formstr);
	return (temp);
}

void		s_form(char *origstr)
{
	char	*temp;
	char	*temp2;
	char	*temp3;

	if (ft_strcmp(origstr, "(null)") == 0)
		temp = ft_strnew(6);
	else
		temp = ft_strnew(ft_strlen(origstr));
	if (arg.precision)
		temp2 = s_pbuild(temp, origstr);
	else
		temp2 = ft_strcpy(temp, origstr);
	if (arg.width)
	{
		if ((int)ft_strlen(origstr) >= WIDTH)
		{
			temp3 = s_wbuild(temp2, origstr);
			if ((PREC < (int)ft_strlen(origstr)) && (WIDTH < (int)ft_strlen(origstr)))
				free(temp2);
			prfree(temp3);
		}
		else
		{
			temp3 = s_wbuild(temp2, origstr);
			prfree(temp3);
			if ((WIDTH) <= (int)ft_strlen(origstr))
				free(temp);
		}
	}
	else
		prfree(temp2);
}
