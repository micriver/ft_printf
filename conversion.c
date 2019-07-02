/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/02 14:01:55 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/02 14:55:15 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*conversion(char str, int i)
{
	char *result;
	va_list args;
	va_start(args, fmt);
	while (fmt[i])
	{
		(fmt[i] == '#') ? SET_BIT(args.arg1, SHARP_F) : fmt[i];
		(fmt[i] == '0') ? SET_BIT(args.arg1, ZERO_F) : fmt[i];
		(fmt[i] == '-') ? SET_BIT(args.arg1, MINUS_F) : fmt[i];
		(fmt[i] == '+') ? SET_BIT(args.arg1, PLUS_F) : fmt[i];
		(fmt[i] == ' ') ? SET_BIT(args.arg1, INVP_F) : fmt[i];
		(isdigit(fmt[i])) ? //have to think about if someone puts a huge number for the width in here 
		result = rj_strncpy(fmt[i]
	}
	va_end(args);
	return (result)
}





//#define CHECK_BIT(var,pos) ((var >> pos) & 1) 
//#define SET_BIT(var,pos) (var |= 1 << pos) 
//#define TOGGLE_BIT(var,pos) (var ^= (1 << pos)) 
