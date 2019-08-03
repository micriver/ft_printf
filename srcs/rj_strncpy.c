/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rj_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:14:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/02 18:51:19 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*insertplussign(char *str)
{
	int i;

	i = 0;
	while (str[i] == ' ' || str[i] == '0')
	{
		if (str[i + 1] == '\0' && str[i] == '0')
		{
			str[i - 1] = '+';
			return (str);
		}
		i++;	
	}
	str[i - 1] = '+';
	return (str);
}

char	*lead_zero_negsign(char *dest, char *src)
{
	if ((ft_atoi(src) >= 0) && (CHECK_BIT(arg.flgmods, PLUS_F)) && (src[0] != '-'))
	{
		if (CHECK_BIT(arg.flgmods, ZERO_F))
			dest = prefixchar('+', dest);
	}
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
	{
		if (CHECK_BIT(arg.flgmods, ZERO_F))
			dest = prependchar(' ', dest);
	}
	else if (src[0] == '-' && (CHECK_BIT(arg.flgmods, ZERO_F)))
	{
		dest = prependchar('-', dest);
		src[0] = '0';
	}
	dest = ft_strjoin(dest, src);
	if (!CHECK_BIT(arg.flgmods, ZERO_F) && CHECK_BIT(arg.flgmods, PLUS_F) \
			&& src[0] != '-')
		dest = insertplussign(dest);
	return (dest);
}

char	*leading_zeros_spaces(char *dest, char *src, int arg_size)
{
	int i;

	i = 0;
	//dest = ft_strnew(arg.width);
	dest = ft_strnew(arg.width - arg_size);
	while (i < (arg.width - arg_size))
	{
		dest[i] = ' ';
		(CHECK_BIT(arg.flgmods, ZERO_F)) ? dest[i++] = '0' : dest[i++];
	}
	return (dest = lead_zero_negsign(dest, src));
}

char	*rj_strncpy(char *src)
{
	char *dest;

	dest = ft_strnew(ft_strlen(src));
	if (arg.width)
	{
		if (arg.width > (int)ft_strlen(src))
			dest = leading_zeros_spaces(dest, src, ft_strlen(src));
		else
			ft_strcpy(dest, src);
	}
	//if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, ZERO_F))
	//	dest = prependchar('-', (ft_strcpy(dest, src)));
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, PLUS_F))
		dest = prependchar('+', (ft_strcpy(dest, src)));
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, INVP_F) && dest[0] != '-')
	{
		if (CHECK_BIT(arg.flgmods, ZERO_F))
			dest = prependchar(' ', src);
	}
	else
		ft_strcpy(dest, src);
	return (dest);
}

