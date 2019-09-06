/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supportpars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/29 15:38:09 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/06 13:06:33 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	predec(char *str, int *i)
{
	if (str[*i] == '.' && (str[*i + 1] == 'f' || str[*i + 1] == 's' \
				|| str[*i + 1] == 'd' || str[*i + 1] == 'x' \
				|| str[*i + 1] == 'o'))
	{
		SET_BIT(arg.flgmods, LONEDEC);
		(*i)++;
	}
	if (str[*i] == '.' && str[*i + 1] == '0' && str[*i + 2] == 'o')
		SET_BIT(arg.flgmods, EXP_0);
}

int		conv_pars(char *str, int *i)
{
	int n;

	n = 0;
	while (CONV_SPECS[n])
	{
		if (str[*i] == CONV_SPECS[n])
		{
			arg.conv = CONV_SPECS[n];
			break ;
		}
		n++;
	}
	(*i) += 1;
	return (1);
}

void	precbuild(char *str, int *i)
{
	int		y;
	int		j;
	char	*result;

	if (str[*i] == '.')
	{
		(*i) += 1;
		j = (*i);
		y = 0;
		result = ft_strnew(j);
		while (ft_isdigit(str[*i]))
		{
			result[y] = str[*i];
			y++;
			(*i)++;
		}
		arg.precision = ft_atoi(result);
		free(result);
	}
}

void	isshort(char *str, int *i)
{
	if (str[*i] == 'h' && str[(*i) + 1] == 'h')
	{
		SET_BIT(arg.flgmods, SGNDCHR);
		(*i) += 2;
	}
	if (str[*i] == 'h' && str[(*i) + 1] != 'h')
	{
		SET_BIT(arg.flgmods, SHOINT);
		(*i)++;
	}
}

void	islonglong(char *str, int *i)
{
	if (str[*i] == 'l' && str[(*i) + 1] != 'l')
	{
		SET_BIT(arg.flgmods, LONGINT);
		(*i)++;
	}
	if (str[*i] == 'l' && str[(*i) + 1] == 'l')
	{
		SET_BIT(arg.flgmods, LNGLNG);
		(*i) += 2;
	}
	if (str[*i] == 'L')
	{
		SET_BIT(arg.flgmods, LNG_D);
		(*i)++;
	}
}
