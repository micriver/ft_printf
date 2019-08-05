/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 12:21:27 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/05 13:37:46 by mirivera         ###   ########.fr       */
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
		(str[*x] == '#') ? SET_BIT(arg.flgmods, SHARP_F) : str[*x];
		(str[*x] == '-') ? SET_BIT(arg.flgmods, MINUS_F) : str[*x];
		(str[*x] == '+') ? SET_BIT(arg.flgmods, PLUS_F) : str[*x];
		(str[*x] == ' ') ? SET_BIT(arg.flgmods, INVP_F) : str[*x];
		(str[*x] == '0') ? SET_BIT(arg.flgmods, ZERO_F) : str[*x];
		(*x)++;
	}
	return (1);
}

void		precision_check(char *str, int *i)
{
	int y;

	y = (*i);
	y++;
	if (ft_strchr("diuoxXfsc", str[y]))
		(*i) = y;
	//else
	//{
	//	while (!ft_isalpha(str[y]) && str[y + 1] != '.')
	//	y++;
	//	if (str[y] != 'f')
	//	{
	//		//I have to add a second zero in place of the '.' char here
	//		(*i)++;
	//		//if (!CHECK_BIT(arg.flgmods, ZERO_F))
	//		//	SET_BIT(arg.flgmods, ZERO_F);
	//	}
	//}
}	


// width modifier parser
int		width_parser(char *str, int *i)
{
	int y;
	int j;
	char *result;
	int *x;

	x = i;
	if (str[*x] == '.')
		return (0);
		//(*x)++;
	//	precision_check(str, i);
	j = (*i);
	y = 0;
	while (!(ft_isalpha(str[j])) && str[j + 1] != '.')
		(j)++;
	result = ft_strnew(j);
	while (!(ft_isalpha(str[*x])) && str[*x] != '.') //we parse the parameters until we get to a '.' or conv specifier
		//ft_strcpy(result, str);
	{
		result[y] = str[*x];
		y++;
		(*x)++;
	}
	arg.width = ft_atoi(result);
	//printf("you're width is = %d\n", arg.width);
	return (1);
}

// precision modifier
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
	while (!ft_isalpha(str[*x])) //we parse the string/numbers until we get to a conversion specifier
	{
		result[y] = str[*x];
		y++;
		(*x)++;
	}
	arg.precision = ft_atoi(result);
	//printf("you're precision is = %d\n", arg.precision);
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
	if (!ft_strchr("diuoxXfsc", fmt[*i]))
			return (0);
	arg.conv = (char)ft_strchr("diuoxXfsc", fmt[*i]);
	(*i) += 1; //this line came from ft_printf, to iterate out of the parsed argument
	return (1);
}

//master parser
void	master_pars(char *fmt, int *i)
{
	flag_parse(fmt, i);
	width_parser(fmt, i);
	precision_parser(fmt, i);
	lengthmod_pars(fmt, i);
	conv_pars(fmt, i);
}
