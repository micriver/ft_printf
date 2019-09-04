/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:05:15 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/04 11:18:14 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	reset_members(void)
{
	arg.width = 0;
	arg.precision = 0;
	arg.conv = 0;
}

void	reset_flags(void)
{
	int i;

	i = 0;
	while (i <= 12)
	{
		if (CHECK_BIT(arg.flgmods, i))
			TOGGLE_BIT(arg.flgmods, i);
		i++;
	}
}

void	reset_struct(void)
{
	reset_flags();
	reset_members();
}
