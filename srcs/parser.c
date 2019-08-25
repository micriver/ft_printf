/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:21:27 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/24 17:45:54 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

int		flag_parse(char *str, int *i)
{
	int *x;

	x = i;
	if (str[*x] == '.')
		return (0);
	while (!ft_isalnum(str[*x]) || str[*x] == '0')
	{
		if (str[*x] == '.')
			return (0);
		(str[*x] == '#') ? SET_BIT(arg.flgmods, SHARP_F) : str[*x];
		(str[*x] == '-') ? SET_BIT(arg.flgmods, MINUS_F) : str[*x];
		(str[*x] == '+') ? SET_BIT(arg.flgmods, PLUS_F) : str[*x];
		(str[*x] == ' ') ? SET_BIT(arg.flgmods, INVP_F) : str[*x];
		(str[*x] == '0') ? SET_BIT(arg.flgmods, ZERO_F) : str[*x];
		(*x)++;
	}
	return (1);
}

int		width_parser(char *str, int *i)
{
	int y;
	int j;
	char *result;
	int *x;

	x = i;
	if (str[*x] == '.')
		return (0);
	j = (*i);
	y = 0;
	while (!(ft_isalpha(str[j])) && str[j + 1] != '.')
		(j)++;
	result = ft_strnew(j);
	while (!(ft_isalpha(str[*x])) && str[*x] != '.')
	{
		result[y] = str[*x];
		y++;
		(*x)++;
	}
	arg.width = ft_atoi(result);
	return (1);
}

int		precision_parser(char *str, int *i)
{
	int *x;
	x = i;
	if (str[*x] != '.')
		return (0);
	else
		(*x) += 1;
	int y;
	int j;
	char *result;

	j = (*i);
	y = 0;
	result = ft_strnew(j);
	while (!ft_isalpha(str[*x]))
	{
		result[y] = str[*x];
		y++;
		(*x)++;
	}
	arg.precision = ft_atoi(result);
	return (1);
}

// length modifier parser (hh), (h), (l), (ll), with diouxX and f with (l), (L) 
int		lengthmod_pars(char *str, int *i)
{
	int *x;

	x = i;
	if (str[*x] != 'h' && str[*x] != 'l' && str[*x] != 'L' )
		return (0);
	else
	{
		if (str[*x] == 'h' && str[(*x) + 1] == 'h')
		{
			SET_BIT(arg.flgmods, SGNDCHR);
			(*x) += 2;
		}
		if (str[*x] == 'h' && str[(*x) + 1] != 'h')
		{
			SET_BIT(arg.flgmods, SHOINT);
			(*x)++;
		}
		if (str[*x] == 'l' && str[(*x) + 1] != 'l')
		{
			SET_BIT(arg.flgmods, LONGINT);
			(*x)++;
		}
		if (str[*x] == 'l' && str[(*x) + 1] == 'l')
		{
			SET_BIT(arg.flgmods, LNGLNG);
			(*x) += 2;
		}
		if (str[*x] == 'L')
		{
			SET_BIT(arg.flgmods, LNG_D);
			(*x)++;
		}
	}
	return (1);
}

int		conv_pars(char *fmt, int *i)
{
	int n;

	n = 0;
	while (CONV_SPECS[n])
	{
		if (fmt[*i] == CONV_SPECS[n])
		{
			arg.conv = CONV_SPECS[n];
			break ;
		}
		n++;
	}
	(*i) += 1;
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
