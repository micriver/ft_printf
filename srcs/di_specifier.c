/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/08 09:34:08 by mirivera         ###   ########.fr       */
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
		res = ft_prependchar('-', res);
	}
	return (res);
}


char	*ft_wi_flag_check(char *res, char *src)
{
	int i;

	i = 0;
	if (CHECK_BIT(arg.flgmods, PLUS_F) && src[0] != '-' && (CHECK_BIT(arg.flgmods, ZERO_F)))
		res = ft_prefixchar('+', res);
	if (CHECK_BIT(arg.flgmods, PLUS_F) && src[0] != '-' && (!CHECK_BIT(arg.flgmods, ZERO_F)))
	{
		while (res[i] == ' ')
			i++;
		res[i - 1] = '+';
	}
	if (CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
		res = ft_prefixchar(' ', res);
	if (src[0] == '-')
	{
		if (CHECK_BIT(arg.flgmods, ZERO_F)) 
		{
			res = ft_srch_rep(res, '-', '0');
			res = ft_prefixchar('-', res);
		}
		else
			ft_srch_rep(res, ft_isdigit(res[i - 1]), '-');
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
	return (res = ft_strjoin(res, src));
}

char 	*ft_build_wiprstr(char *res, char *src)
{
	int i;
	int diff;

	diff = arg.width - (int)ft_strlen(res); //width - precision string built before
	i = 0;
	res = ft_strnew(diff);
	while (i < (arg.width - (int)ft_strlen(res)))
	{
		res[i] = ' ';
		(CHECK_BIT(arg.flgmods, ZERO_F)) ? res[i++] = '0' : res[i++];
	}
	//while (i < diff)
	//	res[i++] = ' ';
	return (res = ft_strjoin(res, src));
	//int diff;

	//diff = arg.width - (int)ft_strlen(res);
	//res = ft_strnew(diff);
	//while (diff)
	//	res[diff--] = ' ';
	//res = ft_strjoin(res, src);
}

char	*di_wipr_fill(char *src)
{
	char *res;
	//build precision string first
	res = ft_build_precstr(src);

	if (arg.precision > arg.width)
	{
		res = ft_pr_flag_check(res, src); //run flag PRECISION prepend/prefix check
		return (res);
	}
	//else if (arg.precision > arg.width)
	//{
	//	
	//}
	else
	{
		res = ft_build_wiprstr(res, src); //fill difference between precision and width with ' '.
		res = ft_wi_flag_check(res, src); //run flag WIDTH prefix check on that string
		return (res); //return that final string
	}
	return (res);
}









char	*di_wipr_ch(char *src)
{
	char *res;

	res = ft_strnew(ft_strlen(src));
	if (arg.width && arg.precision)
	{
		if (((int)ft_strlen(src) > arg.width) && ((int)ft_strlen(src) > arg.precision))
			res = ft_basic_flag_check((ft_strcpy(res, src)), src);  //run flag BASIC prepend/prefix check
		else
			res = di_wipr_fill(src);
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






void	di_print(char *src)
{
	char *res;

	res = ft_strnew(ft_strlen(src));
	//CHECK FOR LEFT JUST OR RIGHT JUST FIRST
	if (arg.width || arg.precision)
		res = di_wipr_ch(src);
	//if ((res = di_wipr_ch(src)))
	//if (arg.precision) 
	//{
	//	if (arg.precision > arg.width)
	//		res = leading_zeros_spaces(res, src, ft_strlen(src));
	//	//create string with (precision/THE MINIMUM) amount of digits
	//	else if (arg.precision > (int)ft_strlen(src))
	//		res = leading_zeros_spaces(res, src, ft_strlen(src));
	//	else if (arg.precision < arg.width)
	//}
	////precision has been handled
	//else if (arg.width)
	//{
	//	if (arg.width > (int)ft_strlen(res))
	//		res = leading_zeros_spaces(res, src, ft_strlen(src));
	//}
	else
		res = ft_basic_flag_check(res, src);  //run flag BASIC prepend/prefix check
	arg.char_count += ft_strlen(res);
	ft_putstr(res);
	reset_flags();
}

void	di_ret_val(va_list args)
{
	char *res;

	if (CHECK_BIT(arg.flgmods, SHOINT))
		res = ft_itoa(va_arg(args, int));
	else if ((CHECK_BIT(arg.flgmods, LNGLNG)) || (CHECK_BIT(arg.flgmods, LONGINT)))
		res = ft_long_itoa(va_arg(args, long long int));
	else
		res = ft_itoa(va_arg(args, int));
	di_print(res);
}

