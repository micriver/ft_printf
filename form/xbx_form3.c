/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xbx_form3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 15:37:23 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 15:48:13 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

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

void		xbx_zeroch2(char *temp, char *origstr)
{
	if (SHARP_FLAG)
		free(origstr);
	arg.char_count += ft_intputstr(temp);
	if ((SHARP_FLAG && ft_strcmp(temp, "0") != 0) && !WIDTH)
		free(temp);
	if (WIDTH)
	{
		if (ZERO_FLAG && !SHARP_FLAG && (WIDTH > PREC))
		{
			free(origstr);
			free(temp);
		}
		if (!ZERO_FLAG && !SHARP_FLAG && (WIDTH > PREC))
		{
			free(temp);
			free(origstr);
		}
		if (ZERO_FLAG && SHARP_FLAG && (WIDTH > PREC))
			free(temp);
		if (!ZERO_FLAG && SHARP_FLAG && (WIDTH > PREC))
			free(temp);
	}
	if (PREC && !WIDTH && !SHARP_FLAG)
		free(temp);
	reset_struct();
}

void		xbx_zeroch3(char *temp, char *origstr)
{
	char	*temp2;

	temp2 = NULL;
	if ((ft_strcmp(origstr, "0") == 0) && (CHECK_BIT(arg.flgmods, LONEDEC)))
	{
		temp2 = ft_strdup("");
		prfree(temp2);
		free(origstr);
	}
	else
	{
		prfree(temp);
		free(origstr);
	}
}
