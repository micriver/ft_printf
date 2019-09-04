/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 11:00:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 22:52:16 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_insertchar(char *formstr, char c, int x)
{
	char	*res;
	int		i;

	i = 0;
	res = ft_strnew(ft_strlen(formstr));
	res = ft_strncpy(res, formstr, x);
	res[x] = c;
	i = x;
	x += 1;
	while (formstr[i])
	{
		res[x] = formstr[i];
		i++;
		x++;
		if (formstr[i + 1] == '\0')
			break ;
	}
	res[x] = '\0';
	formstr = res;
	return (formstr);
	free(res);
}
