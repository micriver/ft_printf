/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:11:59 by mirivera          #+#    #+#             */
/*   Updated: 2019/07/29 14:52:24 by mirivera         ###   ########.fr       */
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
	int flgmods : 16; 
	int width;
	int precision;
	int char_count;
} arg;


int		ft_printf(char *fmt, ...);

/*
** Parsing
*/

void	master_pars(char *fmt, int *i);
//parsing functions go here

/*
** Conversion
*/

char	*conversion(int *i, char *str, va_list args);
char	*s_specifier(va_list args);
char	*di_specifier(int64_t di);
char	*u_specifier(int64_t u);

/*
** Formatting
*/

char	*prependchar(char c, char *str);
char	*insertplussign(char *str);
char	*lead_zero_negsign(char *dest, char *src, int size);
char	*leading_zeros_spaces(char *dest, char *src, int arg_size);
char	*rj_strncpy(char *src);
char	*lj_strncpy(char *src);
char	*prefixchar(char prefix, char *str);
char	*prependstr(char *pstr, char *str);

/*
** Structure
*/

void	print_struct(void);
void	reset_flags(void);

#endif
