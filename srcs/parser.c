/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:21:27 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/12 19:00:35 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdarg.h>
#include <stdio.h>

// flag parser
int		flag_parse(char *str, int *i)
{
	int *x;

	x = i;
	if (str[*x] == '.')
		return (0);
	while (!ft_isalnum(str[*x]) || str[*x] == '0') //we parse the parameters until we get to a conversion specifier
	{
		(str[*x] == '#') ? SET_BIT(args.flgmods, SHARP_F) : str[*x];
		(str[*x] == '-') ? SET_BIT(args.flgmods, MINUS_F) : str[*x];
		(str[*x] == '+') ? SET_BIT(args.flgmods, PLUS_F) : str[*x];
		(str[*x] == ' ') ? SET_BIT(args.flgmods, INVP_F) : str[*x];
		(str[*x] == '0') ? SET_BIT(args.flgmods, ZERO_F) : str[*x];
		(*x)++;
	}
	return (1);
}

// width modifier parser
int		width_parser(char *str, int *i)
{
	int y;
	int j;
	char *result;
	int *x;

	j = (*i);
	y = 0;
	x = i;
	if (str[*x] == '.')
		return (0);
	while (!(ft_isalpha(str[j])) && str[j + 1] != '.')
		(j)++;
	result = ft_strnew(j);
	while (!(ft_isalpha(str[*x])) && str[*x] != '.') //we parse the parameters until we get to a '.' or conv specifier
	{
		result[y] = str[*x];
		y++;
		(*x)++;
	}
	args.width = ft_atoi(result);
	return (1);
}

// precision modifier
int		precision_parser(char *str, int *i)
{
	int y;
	int j;
	char *result;
	int *x;

	j = (*i);
	y = 0;
	x = i;
	if (str[*x] != '.')
		return (0);
	else
		(*x) += 1;
	result = ft_strnew(j);
	while (!ft_isalpha(str[*x])) //we parse the parameters until we get to a conversion specifier
	{
		result[y] = str[*x];
		y++;
		(*x)++;
	}
	args.precision = ft_atoi(result);
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
		(str[*x] == 'h' && str[(*x) + 1] == 'h') ? SET_BIT(args.flgmods, SGNDCHR) : str[*x];
		if (str[*x] == 'h' && str[(*x) + 1] != 'h')
		{
			SET_BIT(args.flgmods, SHOINT);
			x++;
		}
		if (str[*x] == 'l' && str[(*x) + 1] != 'l')
		{
			SET_BIT(args.flgmods, LONGINT);
			x++;
		}
		(str[*x] == 'l' && str[(*x) + 1] == 'l') ? SET_BIT(args.flgmods, LNGLNG) : str[*x];
		(str[*x] == 'L') ? SET_BIT(args.flgmods, LNG_D) : str[*x];
	}
	return (1);
}

//master parser
void	master_pars(char *fmt, int *i)
{
	flag_parse(fmt, i);
	width_parser(fmt, i);
	precision_parser(fmt, i);
	lengthmod_pars(fmt, i);
}
