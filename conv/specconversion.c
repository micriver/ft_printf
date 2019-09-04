/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specconversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:46:57 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/04 15:25:04 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	specconversion(va_list args)
{
	char res;
	char *per_widthres;

	per_widthres = NULL;
	if (arg.conv == '%')
	{
		res = (signed char)va_arg(args, int);
		if (WIDTH)
		{
			per_widthres = per_form(res);
			arg.char_count += ft_intputstr(per_widthres);
			reset_struct();
		}
		else
		{
			arg.char_count += ft_intputchar(res);
			reset_struct();
		}
	}
}
