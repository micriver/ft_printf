/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specconversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:46:57 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/05 11:22:12 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	specconversion(va_list args)
{
	unsigned char res;
	char *per_widthres;

	per_widthres = NULL;
	res = va_arg(args, int);
	if (arg.conv == '%')
	{
		if (WIDTH)
		{
			per_widthres = per_form('%');
			arg.char_count += ft_intputstr(per_widthres);
			reset_struct();
		}
		else
		{
			arg.char_count += ft_intputchar('%');
			reset_struct();
		}
	}
	//else if (arg.conv == '%' && 
}
