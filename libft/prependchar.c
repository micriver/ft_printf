/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   preprendchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 16:24:41 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/02 18:20:53 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*prependchar(char c, char *str)
{
	unsigned int i;
	unsigned int j;
	char *pstr;

	pstr = ft_strnew(ft_strlen(str + 1));
	i = 0;
	j = 0;
	pstr[i] = c;
	while (j < ft_strlen(str + 1))
		pstr[++i] = str[j++];
	pstr[i] = '\0';
	return (pstr);
}

