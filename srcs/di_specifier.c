/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   di_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/18 19:18:08 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/07 15:45:44 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"

char	*ft_flag_check(char *res, char *src)
{
	if (arg.precision)
		ft_pr_flag_check(res, src);
			if (CHECK_BIT(arg.flgmods, PLUS_F) && src[0] != '-')
				res = ft_prependchar('+', res);
			if (CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
				res = ft_prependchar(' ', res);
			if (src[0] == '-')
			{
				ft_srch_rep(dest, '-', '0');
				dest = ft_prependchar('-', dest);
			}
	else if (arg.width)
		ft_wi_flag_check(res, src);
			if (CHECK_BIT(arg.flgmods, PLUS_F) && src[0] != '-')
				res = ft_prefixchar('+', res);
			if (CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
				res = ft_prefixchar(' ', res);
			if (src[0] == '-')
			{
				if (CHECK_BIT(arg.flgmods, ZERO_F)) 
					ft_srch_rep(res, '-', '0');
				res = ft_prefixchar('-', res);
			}
	return (res);
}


char	*di_wipr_fill(char *src)
{
	int i;

	i = 0;
	//build precision string first
	res = ft_strnew(arg.precision - (int)ft_strlen(src));
	while (i < (arg.precision - (int)ft_strlen(src)))
		res[i++] = '0';
	res = ft_strjoin(res, src);

	if (arg.precision > arg.width)
		//run flag prepend/prefix check
		//build precision string and return that
		return (res);
	else
		//run flag prepend/prefix check
		//return that final string



	return (res);
}









char	*di_wipr_ch(char *src)
{
	int arg_size;
	char *res;

	arg_size = ft_strlen(src);
	if ((arg_size > arg.width) && (arg_size > arg.precision))
	{
		//run flag prepend/prefix check
		return (src);
	}
	if (arg.width && arg.precision)
		res = di_wipr_fill(src);
	else if (arg.width && !arg.precision)
		res = di_width_fill(src);
	else if (arg.precision && !arg.width ) 
		res = di_prec_fill(src);
	return (res);
}






void	di_print(char *src)
{
	char *res;

	res = ft_strnew(ft_strlen(src));
	//CHECK FOR LEFT JUST OR RIGHT JUST FIRST
	//if (res = DI_WIPR_CHECK(RES))
	if (arg.precision) 
	{
		if (arg.precision > arg.width)
			res = leading_zeros_spaces(res, src, ft_strlen(src));
		//create string with (precision/THE MINIMUM) amount of digits
		else if (arg.precision > (int)ft_strlen(src))
			res = leading_zeros_spaces(res, src, ft_strlen(src));
		else if (arg.precision < arg.width)
	}
	//precision has been handled
	else if (arg.width)
	{
		if (arg.width > (int)ft_strlen(res))
			res = leading_zeros_spaces(res, src, ft_strlen(src));
	}
	else
		ft_strcpy(res, src);
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

