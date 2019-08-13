/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dui_specifier.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/11 15:06:14 by mirivera          #+#    #+#             */
/*   Updated: 2019/08/13 15:50:28 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/ft_printf.h"
#include <stdio.h>

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
	if ((CHECK_BIT(arg.flgmods, PLUS_F)) && (src[0] != '-') && (!CHECK_BIT(arg.flgmods, ZERO_F)))
	{
		while (res[i] == ' ')
			i++;
		res[i - 1] = '+';
	}
	if (CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
		res = ft_prefixchar(' ', res);
	//if (src[0] == '-' && (arg.width < arg.precision))
	if (src[0] == '-' )
	{
		//might have to control a negative source string function to handle signs
		//if (arg.width < arg.precision)
			//do stuff
		if ((CHECK_BIT(arg.flgmods, ZERO_F)) && !arg.precision)
		{
			res = ft_srch_rep(res, '-', '0');
			res = ft_prefixchar('-', res);
		}
		else if ((arg.width > (int)ft_strlen(src) && (!CHECK_BIT(arg.flgmods, ZERO_F))))
			return (res);
		res = ft_prefixchar('-', res);
	}
	return (res);
}


/*
** The basic flag_check looks at argument strings that are > their width and/or
** precision as well as arguments that do not have either of those values
*/

char	*ft_basic_flag_check(char *res, char *src)
{
	if ((ft_atoi(src) >= 0) && (CHECK_BIT(arg.flgmods, PLUS_F)) && (*src != '-'))
		res = ft_prependchar('+', src);
	else if (ft_atoi(src) >= 0 && CHECK_BIT(arg.flgmods, INVP_F) && src[0] != '-')
	{
		if (CHECK_BIT(arg.flgmods, ZERO_F))
			res = ft_prependchar(' ', src);
	}
	else if (ft_strchr(res, '-'))
		return (res);
	else
		return (src);
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

//WAS GOING THROUGH THIS FUNCTION WITH ELIJAH, NEEDS TO BE FIXED!
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
		temp = ft_strjoin(temp, res);
		free(res);
		res = ft_srch_rep(temp, '-', '0');
		free(temp);
		temp
		res = ft_prependchar('-', temp);
	}
	res = temp;
	free(temp);
	return (res);
}

char 	*ft_build_wiprstr(char *res)
{
	int diff;
	int i;
	char *wiprstr;

	i = -1;
	diff = arg.width - (int)ft_strlen(res); //width - precision string built before
	wiprstr = ft_strnew(diff);
	//while (diff)
	//{
	//	wiprstr[diff--] = ' ';
	//	(CHECK_BIT(arg.flgmods, ZERO_F) && !arg.precision) ? wiprstr[diff--] = '0' : wiprstr[diff];
	//}
	while (i++ < diff)
	{
		wiprstr[i] = ' ';
		(CHECK_BIT(arg.flgmods, ZERO_F) && !arg.precision) ? wiprstr[i++] = '0' : wiprstr[i];
	}
	wiprstr[diff] = '\0';
	//printf ("this is your new width difference string: %s\n", wiprstr);
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
		return (res = ft_pr_flag_check(res, src)); //run flag PRECISION prepend/prefix check
	else
	{
		res = ft_build_wiprstr(res); //fill difference between precision and width with ' '.
		return (res = ft_wi_flag_check(res, src)); //run flag WIDTH prefix check on that string
	}
	return (res);
}

char	*dui_build_check(char *res, char *src)
{
	if (((int)ft_strlen(src) > arg.width) && ((int)ft_strlen(src) > arg.precision))
		return (res = ft_basic_flag_check((ft_strcpy(res, src)), src));  //run flag BASIC prepend/prefix check
	else if (((int)ft_strlen(src) < arg.width) && ((int)ft_strlen(src) > arg.precision))
		return (res = ft_build_wiprstr(ft_strcpy(res, src)));  //run flag BASIC prepend/prefix check
	else
		return (res = dui_wipr_fill(src));
}

char	*dui_wi_check(char *res, char *src)
{
	if (((int)ft_strlen(src) > arg.width))
	{
		res = ft_strcpy(ft_strnew(ft_strlen(src)), src);
		return (res = ft_basic_flag_check(res, src)); //width flag check
	}
	else
	{
		//res = ft_strnew(ft_strlen(src));
		return (res = ft_wi_flag_check(ft_build_widthstr(src), src)); //width flag check
	}
}

char	*dui_pr_check(char *res, char *src)
{
		if ((int)ft_strlen(src) > arg.precision)
			return (res = ft_pr_flag_check(ft_strcpy(res, src), src)); //run flag PRECISION prepend/prefix check
		else
			return (res = ft_pr_flag_check(ft_build_precstr(src), src)); //run flag PRECISION prepend/prefix check
}

char	*dui_wipr_ch(char *src)
{
	char *res;

	res = ft_strnew((int)ft_strlen(src));
	if (arg.width && arg.precision)
		return (res = dui_build_check(res, src));
	else if (arg.width && !arg.precision)
		return (res = dui_wi_check(res, src));
	else if (arg.precision && !arg.width ) 
		return (res = dui_pr_check(res, src));
	else
		return (src);
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

//you can use long long itoa for all of them!!!!!
//230 can just be (if), get rid of first two lines
	if (CHECK_BIT(arg.flgmods, SHOINT))
		res = ft_itoa(va_arg(args, int));
	else if ((CHECK_BIT(arg.flgmods, LNGLNG)) || (CHECK_BIT(arg.flgmods, LONGINT)))
		res = ft_long_itoa(va_arg(args, long long int));
	else
		res = ft_itoa(va_arg(args, int));
	dui_print(res);
}

