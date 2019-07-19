/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/19 12:01:11 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*di_specifier(va_list args)
{
	char *result;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_itoa((short int)va_arg(args, int));
	else if (CHECK_BIT(arg.flgmods, LONGINT))
		result = ft_itoa((long int)va_arg(args, int));
	else if (CHECK_BIT(arg.flgmods, LNGLNG))
		//ft_itoa is not outputting correct number
		//does it need to be itoa base?
		result = ft_itoa((long long int)va_arg(args, int));
	else
		result = NULL;
	//(CHECK_BIT(arg.flgmods, SHOINT)) ? result = ft_itoa(va_arg(args, (short int))) : args;
	return (result);
}
