/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:11:59 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/25 14:12:15 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"
# include "get_next_line.h"

#define CHECK_BIT(var,pos) ((var >> pos) & 1) 
#define SET_BIT(var,pos) (var |= 1 << pos) 
#define TOGGLE_BIT(var,pos) (var ^= (1 << pos)) 

#define ZERO_F (0)
#define MINUS_F (1)
#define PLUS_F (2)
#define SHARP_F (3)
#define INVP_F (4)
#define SGNDCHR (5)
#define SHOINT (6)
#define LONGINT (7)
#define LNGLNG (8)
#define LNG_D (9)

struct arguments
{
	int flgmods : 16; //make sure that you set the bit width to only the amount of bits you actually need!!! eg, the # of flags/modifiers you'll be using
	int width;
	int precision;
	int char_count;
} arg;


int		ft_printf(char *fmt, ...);
void	master_pars(char *fmt, int *i);
char	*conversion(int *i, char *str, va_list args);
char	*prependchar(char c, char *str);
char	*insertplussign(char *str);
char	*lead_zero_negsign(char *dest, char *src, int size);
char	*leading_zeros_spaces(char *dest, char *src, int arg_size);
char	*rj_strncpy(char *src);
char	*lj_strncpy(char *src);
char	*prefixchar(char prefix, char *str);
char	*prependstr(char *pstr, char *str);
//char	*di_specifier(va_list args);
char	*s_specifier(va_list args);
char	*di_specifier(int64_t di);

#endif
