/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rj_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 13:14:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/21 10:35:58 by mirivera         ###   ########.fr       */
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
			dest = ft_prefixchar('+', dest);
	}
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
	{
		if (CHECK_BIT(arg.flgmods, ZERO_F))
			dest = ft_prependchar(' ', dest);
	}
	else if (src[0] == '-' && (CHECK_BIT(arg.flgmods, ZERO_F)))
	{
		dest = ft_prependchar('-', dest);
		src[0] = '0';
	}
	dest = ft_strjoin(dest, src);
	if (!CHECK_BIT(arg.flgmods, ZERO_F) && CHECK_BIT(arg.flgmods, PLUS_F) \
			&& src[0] != '-')
		dest = insertplussign(dest);
	return (dest);
}

char	*wipr_join(char *src)
{
	char *widthstring;
	int i;

	i = 0;
	widthstring = ft_strnew(arg.width - (ft_strlen(src)));
	while (i < arg.width - ((int)ft_strlen(src)))
		widthstring[i++] = ' ';
	return (src = ft_strjoin(widthstring, src));
}

char	*leading_zeros_spaces(char *dest, char *src, int arg_size)
{
	int i;

	i = 0;
	if (arg.precision)
	{
		dest = ft_strnew(arg.precision - (int)ft_strlen(src));
		while (i < (arg.precision - (int)ft_strlen(src)))
			dest[i++] = '0';
		if (CHECK_BIT(arg.flgmods, PLUS_F) && src[0] != '-')
			dest = ft_prependchar('+', dest);
		if (CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
			dest = ft_prependchar(' ', dest);
		dest = ft_strjoin(dest, src);
		if (src[0] == '-')
		{
			ft_srch_rep(dest, '-', '0');
			dest = ft_prependchar('-', dest);
		}
		if (arg.precision > arg.width)
			return (dest);
		else
			dest = wipr_join(dest);
			//dest = ft_strnew(arg.width - ft_strlen(dest));
		return (dest);
	}
	dest = ft_strnew(arg.width - arg_size);
	while (i < (arg.width - arg_size))
	{
		dest[i] = ' ';
		(CHECK_BIT(arg.flgmods, ZERO_F)) ? dest[i++] = '0' : dest[i++];
	}
	return (dest = lead_zero_negsign(dest, src));
}

//char	*precision_str(char argstring)
//{
//	unsigned int i;
//	unsigned int count;
//	
//	i = 0;
//	count = 0;
//	while (argstring[0] == '-' || argstring[0] == '+' argstring[i] != '\0')
//		(ft_isdigit(argstring[i])) ? count++ : count;
//	
//
//}

char	*rj_strncpy(char *src)
{
	char *dest;

	dest = ft_strnew(ft_strlen(src));
	if (arg.width) //create string with (width) amount of characters
	{
		if (arg.width > (int)ft_strlen(src))
			dest = leading_zeros_spaces(dest, src, ft_strlen(src));
		else
			ft_strcpy(dest, src);
	}
	//handle precision string building here
	//if (arg.precision) //create string with (precision) amount of digits
	//{
	//	if (arg.precision > (int)ft_strlen(src))
	//		dest = leading_zeros_spaces(dest, src, ft_strlen(src));
	//	else
	//		ft_strcpy(dest, src);
	//}
	//if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, ZERO_F))
	//	dest = ft_prependchar('-', (ft_strcpy(dest, src)));
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, PLUS_F))
		dest = ft_prependchar('+', (ft_strcpy(dest, src)));
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, INVP_F) && dest[0] != '-')
	{
		if (CHECK_BIT(arg.flgmods, ZERO_F))
			dest = ft_prependchar(' ', src);
	}
	else
		ft_strcpy(dest, src);
	return (dest);
}

