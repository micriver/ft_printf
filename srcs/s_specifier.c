/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_specifier.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/23 11:36:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/23 11:56:18 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

char	*s_specifier(va_list args)
{
	char *result;
	char *temp;
	char *argument;

	result = NULL;
	//unsigned int x;
	temp = va_arg(args, char *);
	argument = ft_strnew(ft_strlen(temp));
	//temp = ft_strnew(ft_strlen((const char *)args));
	result = ft_strcpy(argument, temp);
	return (result);
}

