/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:21:27 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/06 13:05:30 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		flag_parse(char *str, int *i)
{
	if ((str[*i] == '.' || str[*i] == '%') && \
			(str[*i] != ' ' || str[*i] != '#'))
		return (0);
	while ((!ft_isalnum(str[*i]) || str[*i] == '0') && str[*i] != '%')
	{
		if (str[*i] == '.')
			return (0);
		(str[*i] == '#') ? SET_BIT(arg.flgmods, SHARP_F) : str[*i];
		(str[*i] == '-') ? SET_BIT(arg.flgmods, MINUS_F) : str[*i];
		(str[*i] == '+') ? SET_BIT(arg.flgmods, PLUS_F) : str[*i];
		(str[*i] == ' ') ? SET_BIT(arg.flgmods, INVP_F) : str[*i];
		(str[*i] == '0') ? SET_BIT(arg.flgmods, ZERO_F) : str[*i];
		(*i)++;
	}
	return (1);
}

int		width_parser(char *str, int *i)
{
	int		y;
	int		j;
	char	*result;

	if (str[*i] == '.' || str[*i] == '%')
		return (0);
	j = (*i);
	y = 0;
	while (ft_isdigit(str[j]))
		(j)++;
	result = ft_strnew(j);
	while (ft_isdigit(str[*i]))
	{
		result[y] = str[*i];
		y++;
		(*i)++;
	}
	arg.width = ft_atoi(result);
	free(result);
	return (1);
}

/*
** First two checks are for my f_conv.
** They give value to my struct for later use
*/

int		precision_parser(char *str, int *i)
{
	if (str[*i] == '%')
		return (0);
	if (str[*i] == 'f')
	{
		arg.precision = 6;
		return (0);
	}
	if (str[*i] == '.')
		predec(str, i);
	if (str[*i] == '.')
		precbuild(str, i);
	return (1);
}

int		lengthmod_pars(char *str, int *i)
{
	if (str[*i] != 'h' && str[*i] != 'l' && str[*i] != 'L')
		return (0);
	else
	{
		isshort(str, i);
		islonglong(str, i);
	}
	return (1);
}

void	master_pars(char *fmt, int *i)
{
	flag_parse(fmt, i);
	width_parser(fmt, i);
	precision_parser(fmt, i);
	lengthmod_pars(fmt, i);
	conv_pars(fmt, i);
}
