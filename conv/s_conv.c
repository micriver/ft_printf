/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_conv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 19:52:03 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/30 00:50:31 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char				*s_form(char *orig)
{
	char	*formstr;
	int		i;
	int		diff;

	i = 0;
	if (orig == NULL)
		diff = arg.width - 6;
	else
		diff = arg.width - (int)ft_strlen(orig);
	if (CHECK_BIT(arg.flgmods, MINUS_F))
	{
		formstr = ft_strnew(arg.width);
		while (i < diff)
			formstr[i++] = ' ';
		formstr = ft_strjoin(orig, formstr);
	}
	else
	{
		formstr = ft_strnew(arg.width);
		while (i < diff)
			formstr[i++] = ' ';
		formstr = ft_strjoin(formstr, orig);
	}
	return (formstr);
	free(formstr);
}

void	s_conv(va_list args)
{
	char *res;

	res = va_arg(args, char *);
	if ((res == NULL) && arg.width < 6)
		arg.char_count += ft_intputstr("(null)");
	else if ((res == NULL) && arg.width > 6)
	{
		res = s_form("(null)");
		arg.char_count += ft_intputstr(res);
	}
	else if (((int)ft_strlen(res) > arg.width))
	{
		res = s_form(res);
		arg.char_count += ft_intputstr(res);
	}
	else if (res == NULL)
	{
		res = s_form("(null)");
		arg.char_count += ft_intputstr(res);
	}
	else
	{
		res = s_form(res);
		arg.char_count += ft_intputstr(res);
	}
	free(res);
	reset_struct();
}
