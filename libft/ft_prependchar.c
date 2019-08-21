/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prependchar.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD:libft/ft_prependchar.c
/*   Created: 2019/08/06 14:31:48 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/06 16:11:22 by mirivera         ###   ########.fr       */
=======
/*   Created: 2019/07/31 16:24:41 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/02 18:20:53 by mirivera         ###   ########.fr       */
>>>>>>> master:libft/prependchar.c
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prependchar(char c, char *str)
{
	unsigned int i;
	unsigned int j;
	char *pstr;

	pstr = ft_strnew(ft_strlen(str) + 1);
	i = 0;
	j = 0;
	pstr[i] = c;
	while (j < ft_strlen(str) + 1)
		pstr[++i] = str[j++];
	pstr[i] = '\0';
	return (pstr);
}

