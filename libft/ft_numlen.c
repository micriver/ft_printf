/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 11:09:46 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/27 11:23:07 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(int number)
{
	int counter;

	counter = 0;
	while (number > 0)
	{
		number = number / 10;
		counter++;
	}
	return (counter);
}
