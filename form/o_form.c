/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   o_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 18:57:50 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 16:22:13 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void			o_pbuild(char *temp, char *origstr)
{
	int		i;
	char	*temp2;

	i = 0;
	if (SHARP_FLAG && PREC <= (int)ft_strlen(origstr) && \
			(ft_strcmp(origstr, "0") != 0))
		PREC = (int)ft_strlen(origstr) + 1;
	if (arg.precision >= (int)ft_strlen(origstr))
	{
		temp2 = ft_strnew(arg.precision - (int)ft_strlen(origstr));
		while (i < (arg.precision - (int)ft_strlen(origstr)))
			temp2[i++] = '0';
		arg.char_count += ft_intputstr(temp2);
		arg.char_count += ft_intputstr(origstr);
		free(temp2);
	}
	else if (!SHARP_FLAG)
		ft_strcpy(temp, origstr);
}

void			o_wstrbuild(char *origstr)
{
	int		i;
	int		diff;
	int		precdiff;
	char	*formstr;

	i = 0;
	if (PREC && (PREC >= (int)ft_strlen(origstr)))
	{
		precdiff = PREC - (int)ft_strlen(origstr);
		diff = WIDTH - ((int)ft_strlen(origstr) + precdiff);
	}
	else
		diff = WIDTH - (int)ft_strlen(origstr);
	formstr = ft_strnew(diff);
	while (i < diff)
	{
		formstr[i] = ' ';
		((ZERO_FLAG) && !PREC) ? formstr[i] = '0' : formstr[i];
		i++;
	}
	formstr[diff] = '\0';
	arg.char_count += ft_intputstr(formstr);
	free(formstr);
}

void			o_lonedecf(char *temp, char *origstr)
{
	if ((ft_strcmp(origstr, "0") == 0) && !SHARP_FLAG)
		temp[0] = '\0';
	else if ((ft_strcmp(origstr, "0") == 0) && EXP_0_F \
			&& !SHARP_FLAG)
		temp[0] = '\0';
	else
		ft_strcpy(temp, origstr);
}

/*
** The precision of the number is increased
** to force the first character of the output string to a zero
*/

void			o_sharpf(char *temp, char *origstr)
{
	if (ft_strcmp(origstr, "0") == 0)
		ft_strcpy(temp, origstr);
	if ((ft_strcmp(origstr, "0") == 0) && LONEDEC_F)
		temp[0] = '\0';
	else
	{
		ft_strcpy(temp, origstr);
		PREC += 1;
	}
}

void			o_form(char *origstr)
{
	char		temp[64];

	if (SHARP_FLAG)
		o_sharpf(temp, origstr);
	if (LONEDEC_F || EXP_0_F)
		o_lonedecf(temp, origstr);
	if (MINUS_FLAG)
		o_ifminus(temp, origstr);
	else if (!MINUS_FLAG && (WIDTH || PREC))
		o_nominus(temp, origstr);
	else
	{
		if (!LONEDEC_F && !EXP_0_F)
			arg.char_count += ft_intputstr(origstr);
		else
			arg.char_count += ft_intputstr(temp);
	}
	free(origstr);
	reset_struct();
}
