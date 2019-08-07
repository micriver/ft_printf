/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left_justfied_strncpy.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/21 12:23:45 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/06 15:01:46 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*lj_strncpy(char *src)
{
	char *dest;
	int i;
	int arg_size;

	arg_size = ft_strlen(src);
	if (arg_size > arg.width)
		dest = ft_strnew(arg_size);
	else
		dest = ft_strnew(arg.width);
	ft_strcpy(dest, src);
	if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, PLUS_F))
		dest = ft_prependchar('+', src);
	else if(ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, INVP_F)) 
		dest = ft_prependchar(' ', src);
	if (arg_size > arg.width)
		return (dest);
	i = ft_strlen(dest);
	while (i < arg.width)
		dest[i++] = ' ';
	return (dest);
}
