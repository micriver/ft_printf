/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reset_struct.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/17 20:05:15 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/24 19:05:39 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

void	reset_flags(void)
{
	int i;

	i = 0;
	while (i < 9)
	{
		if (CHECK_BIT(arg.flgmods, i))
			TOGGLE_BIT(arg.flgmods, i);
		i++;
	}
}
