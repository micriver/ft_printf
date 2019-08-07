/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prefixchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/06 14:32:15 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/06 15:11:39 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prefixchar(char prefix, char *str)
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
