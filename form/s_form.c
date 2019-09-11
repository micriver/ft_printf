/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:21:20 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 11:42:25 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char		*s_pbuild(char *temp)
{
	int x;

	x = 0;
	if (arg.precision > arg.width)
		arg.width = 0;
	if (PREC < (int)ft_strlen(temp))
		temp[PREC] = '\0';
	if (PREC > (int)ft_strlen(temp))
		return (temp);
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
			temp = ft_strjoin(formstr, temp2);
			free(temp2);
		}
	}
	free(formstr);
	return (temp);
}

char		*s_lonedec(void)
{
	char	*formstr;
	int		i;

	i = 0;
	if (WIDTH)
	{
		formstr = ft_strnew(WIDTH);
		while (i < WIDTH)
			formstr[i++] = ' ';
		formstr[i] = '\0';
		return (formstr);
	}
	else
		return ("");
}

void		s_form(char *origstr)
{
	char	*temp;
	char	*temp2;

	if ((!PREC) && (!WIDTH) && (!LONEDEC_F) && (!arg.fd))
		arg.char_count += ft_intputstr(origstr);
	else if ((PREC) && (!LONEDEC_F))
	{
		temp = ft_strdup(origstr);
		temp = s_pbuild(temp);
		if (!WIDTH)
			prfree(temp);
	}
	if ((WIDTH) && (!LONEDEC_F))
	{
		if (PREC)
		{
			temp2 = s_wbuild(temp, origstr);
			prfree(temp2);
		}
		else
		{
			temp = ft_strdup(origstr);
			temp2 = s_wbuild(temp, origstr);
			prfree(temp2);
		}
	}
	else if ((LONEDEC_F) && (PREC == 0))
	{
		temp = s_lonedec();
		prfree(temp);
	}
	else if (arg.fd)
		prfree(origstr);
}
