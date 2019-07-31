/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprendchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:24:41 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/31 16:28:37 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*prependchar(char *pstr, char *str)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	while (pstr[i] != '\0')
		i++;
	j = 0;
	while (str[j] != '\0')
		pstr[i++] = str[j++];
	pstr[i] = '\0';
	return (pstr);
}
