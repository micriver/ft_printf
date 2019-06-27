/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prefixchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 19:48:43 by mirivera          #+#    #+#             */
/*   Updated: 2019/06/26 19:49:13 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*prefixchar(char prefix, const char *str)
{
	unsigned int	i;
	unsigned int	j;
	char			*temp;

	temp = ft_strnew(ft_strlen(str));
	i = 0;
	j = 0;
	temp[0] = prefix;
	while (str[i] != '\0')
		temp[++j] = str[++i];
	temp[j] = '\0';
	return (temp);
}
