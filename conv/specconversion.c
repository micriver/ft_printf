/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specconversion.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 14:46:57 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/05 13:20:22 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	specconversion(va_list args)
{
	unsigned char	res;
	char			*per_widthres;

	per_widthres = NULL;
	res = va_arg(args, int);
	if (arg.conv == '%')
	{
		if (WIDTH)
		{
			per_widthres = per_form('%');
			prfree(per_widthres);
		}
		else
		{
			arg.char_count += ft_intputchar('%');
			free(per_widthres);
			reset_struct();
		}
	}
}
