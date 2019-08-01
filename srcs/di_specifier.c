/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/01 16:03:33 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//on the dui branch now!

#include "../headers/ft_printf.h"

char	*di_ret_val(va_list args)
{
	char *result;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		result = ft_itoa(va_arg(args, int));
	else if ((CHECK_BIT(arg.flgmods, LNGLNG)) || (CHECK_BIT(arg.flgmods, LONGINT)))
		result = ft_long_itoa(va_arg(args, long long int));
	else
		result = ft_itoa(va_arg(args, int));
	return (result);
}

