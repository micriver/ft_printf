/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:06:14 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/11 15:09:02 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

//make a flag check .c file and place functions inside there
char	*ft_pr_flag_check(char *res, char *src)
{
	if (CHECK_BIT(arg.flgmods, PLUS_F) && src[0] != '-')
		res = ft_prependchar('+', res);
	if (CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
		res = ft_prependchar(' ', res);
	if (src[0] == '-')
	{
		ft_srch_rep(res, '-', '0');
		res = ft_prefixchar('-', res);
	}
	return (res);
}


char	*ft_wi_flag_check(char *res, char *src)
{
	int i;

	i = 0;
	if (CHECK_BIT(arg.flgmods, PLUS_F) && src[0] != '-' && (CHECK_BIT(arg.flgmods, ZERO_F)) && !arg.precision)
		res = ft_prefixchar('+', res);
	if (CHECK_BIT(arg.flgmods, PLUS_F) && src[0] != '-' && (!CHECK_BIT(arg.flgmods, ZERO_F)))
	{
		while (res[i] == ' ')
			i++;
		res[i - 1] = '+';
	}
	if (CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
		res = ft_prefixchar(' ', res);
	if (src[0] == '-' && (arg.width < arg.precision))
	{
		if ((CHECK_BIT(arg.flgmods, ZERO_F)) && !arg.precision)
		{
			res = ft_srch_rep(res, '-', '0');
			res = ft_prefixchar('-', res);
		}
		//else
		//	ft_srch_rep(res, ft_isdigit(res[i - 1]), '-');
		res = ft_prefixchar('-', res);
	}
	return (res);
}


char	*ft_basic_flag_check(char *res, char *src)
{
	if ((ft_atoi(src) >= 0) && (CHECK_BIT(arg.flgmods, PLUS_F)) && (src[0] != '-'))
		res = ft_prependchar('+', src);
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
	{
		if (CHECK_BIT(arg.flgmods, ZERO_F))
			res = ft_prependchar(' ', src);
	}
	return (res);
}

char 	*ft_build_widthstr(char *src)
{
	char *res;
	int i;

	i = 0;
	res = ft_strnew(arg.width - (int)ft_strlen(src));
	while (i < (arg.width - (int)ft_strlen(src)))
	{
		res[i] = ' ';
		(CHECK_BIT(arg.flgmods, ZERO_F)) ? res[i++] = '0' : res[i++];
	}
	return (res = ft_strjoin(res, src));
}

char 	*ft_build_precstr(char *src)
{
	char *res;
	int i;

	i = 0;
	res = ft_strnew(arg.precision - (int)ft_strlen(src));
	while (i < (arg.precision - (int)ft_strlen(src)))
		res[i++] = '0';
	res = ft_strjoin(res, src);
	if (src[0] == '-' && ((int)ft_strlen(src) < arg.precision))
	{
		res = ft_srch_rep(res, '-', '0');
		res = ft_prependchar('-', res);
	}
	return (res);
}

char 	*ft_build_wiprstr(char *res)
{
	int diff;
	char *wiprstr;

	diff = arg.width - (int)ft_strlen(res); //width - precision string built before
	wiprstr = ft_strnew(diff);
	while (diff)
	{
		wiprstr[diff--] = ' ';
		(CHECK_BIT(arg.flgmods, ZERO_F) && !arg.precision) ? wiprstr[diff--] = '0' : wiprstr[diff--];
	}
	return (res = ft_strjoin(wiprstr, res));
}

char	*dui_wipr_fill(char *src)
{
	char *res;
	//build precision string first
	res = ft_build_precstr(src);
	if (CHECK_BIT(arg.flgmods, ZERO_F) && CHECK_BIT(arg.flgmods, PLUS_F) && arg.precision && src[0] != '-')
		res = ft_prependchar('+', res);
	if (arg.precision > arg.width)
	{
		res = ft_pr_flag_check(res, src); //run flag PRECISION prepend/prefix check
		return (res);
	}
	else
	{
		res = ft_build_wiprstr(res); //fill difference between precision and width with ' '.
		res = ft_wi_flag_check(res, src); //run flag WIDTH prefix check on that string
		return (res); //return that final string
	}
	return (res);
}

char	*dui_wipr_ch(char *src)
{
	char *res;

	res = ft_strnew(ft_strlen(src));
	if (arg.width && arg.precision)
	{
		if (((int)ft_strlen(src) > arg.width) && ((int)ft_strlen(src) > arg.precision))
			res = ft_basic_flag_check((ft_strcpy(res, src)), src);  //run flag BASIC prepend/prefix check
		else
			res = dui_wipr_fill(src);
	}
	else if (arg.width && !arg.precision)
	{
		res = ft_build_widthstr(src);
		res = ft_wi_flag_check(res, src); //width flag check
	}
	else if (arg.precision && !arg.width ) 
	{
		res = ft_build_precstr(src);
		res = ft_pr_flag_check(res, src); //run flag PRECISION prepend/prefix check
	}
	else
		return (src);
	return (res);
}

void	dui_print(char *src)
{
	char *res;

	res = ft_strnew(ft_strlen(src));
	//CHECK FOR LEFT JUST OR RIGHT JUST FIRST
	if (arg.width || arg.precision)
		res = dui_wipr_ch(src);
	else
		res = ft_basic_flag_check(res, src); 
	arg.char_count += ft_strlen(res);
	ft_putstr(res);
	reset_flags();
}

void	dui_ret_val(va_list args)
{
	char *res;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		res = ft_itoa(va_arg(args, int));
	else if ((CHECK_BIT(arg.flgmods, LNGLNG)) || (CHECK_BIT(arg.flgmods, LONGINT)))
		res = ft_long_itoa(va_arg(args, long long int));
	else
		res = ft_itoa(va_arg(args, int));
	dui_print(res);
}

