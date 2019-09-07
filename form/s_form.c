/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 23:55:25 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/07 14:47:29 by mirivera         ###   ########.fr       */
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
	temp[x] = '\0';
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
	{
		temp2 = temp;
		temp2 = "";
		free(temp);
		while (i < (WIDTH - (int)ft_strlen(temp2)))
			formstr[i++] = ' ';
		temp = ft_strjoin(temp2, formstr);
		return (temp);
	}
	if (ft_strcmp(origstr, "(null)") == 0)
		diff = arg.width - (int)ft_strlen(temp);
	else if ((arg.width >= (int)ft_strlen(temp)) || (ft_strcmp(origstr, "(null)") == 0))
		diff = arg.width - (int)ft_strlen(temp);
	temp2 = NULL;
	if (arg.width < (int)ft_strlen(temp))
	{
		temp = ft_strcpy(temp, origstr);
		free(formstr);
		return (temp);
	}
	else
	{
		temp2 = temp;
		while (i < diff)
			formstr[i++] = ' ';
		if (CHECK_BIT(arg.flgmods, MINUS_F))
		{
			temp = ft_strjoin(temp2, formstr);
			free(temp2);
		}
		else
		{
			//if (CHECK_BIT(arg.flgmods, LONEDEC))
			//	free(temp);
			temp = ft_strjoin(formstr, temp2);
			free(temp2);
		}
	}
	free(formstr);
	return (temp);
}

void		s_form(char *origstr)
{
	char	*temp;
	char	*temp2;

	temp = ft_strdup(origstr);
	if (arg.precision)
		temp = s_pbuild(temp, origstr);
	if (arg.width)
	{
		temp2 = s_wbuild(temp, origstr);
		prfree(temp2);
	}
	else
		prfree(temp);
}
