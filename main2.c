/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:24:03 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/06 21:28:33 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "headers/ft_printf.h"
#include <stdio.h>

int		main(void)
{
	//ft_printf("%x\n", 12);
	//ft_printf("[%x]\n", 100);
	//ft_printf("[%10.5x]\n", 100);
	printf("RES1: [%d]\n", ft_printf("%% hi im paulina %d %s ble ble hex [%x] [%10.5x] [%5s]\n", -571236235, "hiiiiii", 100, 54545123, "IM GUCCI"));
	printf("RES2: [%d]\n", printf("%% hi im paulina %d %s ble ble hex [%x] [%10.5x] [%5s]\n", -571236235, "hiiiiii", 100, 54545123, "IM GUCCI"));
	//while (1);
	return (0);
}
