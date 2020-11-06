/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/07 16:21:20 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 13:33:19 by mirivera         ###   ########.fr       */
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

char		*s_greaterthanbuild(char *temp, int diff)
{
	char	*temp2;
	char	*formstr;
	int		i;

	i = 0;
	temp2 = NULL;
	temp2 = temp;
	formstr = ft_strnew(arg.width);
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
	free(formstr);
	return (temp);
}

char		*s_wbuild(char *temp, char *origstr)
{
	int		diff;

	if (ft_strcmp(origstr, "(null)") == 0)
		diff = arg.width - (int)ft_strlen(temp);
	else if ((arg.width >= (int)ft_strlen(temp)) || \
			(ft_strcmp(origstr, "(null)") == 0))
		diff = arg.width - (int)ft_strlen(temp);
	if (arg.width < (int)ft_strlen(temp))
	{
		temp = ft_strcpy(temp, origstr);
		return (temp);
	}
	else
		temp = s_greaterthanbuild(temp, diff);
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
		s_widthhandle(temp, origstr);
	else if ((LONEDEC_F) && (PREC == 0))
	{
		temp = s_lonedec();
		prfree(temp);
	}
	else if (arg.fd)
		prfree(origstr);
}
