/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prependstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 18:42:02 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/26 19:43:14 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*prependstr(char *pstr, const char *str)
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
