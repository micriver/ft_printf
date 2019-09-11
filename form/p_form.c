/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   p_form.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/31 13:05:31 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 10:36:10 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void		p_form(char *orig)
{
	char	*temp;
	int		i;

	i = 0;
	if (CHECK_BIT(arg.flgmods, MINUS_F))
	{
		temp = ft_strnew(WIDTH);
		while (i < arg.width - (int)ft_strlen(orig))
			temp[i++] = ' ';
		arg.char_count += ft_intputstr(orig);
		arg.char_count += ft_intputstr(temp);
		free(orig);
		free(temp);
	}
	else
	{
		temp = ft_strnew(WIDTH);
		while (i < arg.width - (int)ft_strlen(orig))
			temp[i++] = ' ';
		arg.char_count += ft_intputstr(temp);
		arg.char_count += ft_intputstr(orig);
		free(orig);
		free(temp);
	}
}
