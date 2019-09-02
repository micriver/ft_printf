/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:11:59 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/02 11:27:27 by mirivera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../libft/get_next_line.h"

# define CONV_SPECS "scdiuoxXpf$%*"
# define WIDTH arg.width
# define PREC arg.precision

# define CHECK_BIT(var,pos) ((var >> pos) & 1)
# define SET_BIT(var,pos) (var |= 1 << pos)
# define TOGGLE_BIT(var,pos) (var ^= (1 << pos))

# define ZERO_F (0)
# define MINUS_F (1)
# define PLUS_F (2)
# define SHARP_F (3)
# define INVP_F (4)
# define SGNDCHR (5)
# define SHOINT (6)
# define LONGINT (7)
# define LNGLNG (8)
# define LNG_D (9)
# define LONEDEC (10)

int					ft_printf(char *fmt, ...);

/*
** Conversion
*/

void				conversion(int *i, char *str, va_list args);
void				dui_ret_val(va_list args);
char				*u_specifier(int64_t u);
void				dui_print(char *src);
void				ull_ret_val(va_list args);

void				s_conv(va_list args);
void				c_conv(va_list args);
void				dui_conv(va_list args);
void				u_conv(va_list args);
void				i_conv(va_list args);
void				f_conv(va_list args);
void				o_conv(va_list args);
void				x_conv(va_list args);
void				bx_conv(va_list args);
void				ox_conv(va_list args);
void				p_conv(va_list args);

/*
** Conversion support functions 
*/

char				*roundup(char *str);
long double			decconv(long double dec);

/*
** Structs
*/

typedef struct		s_dispatch_table
{
	char			specifier;
	void			(*function)();
}					t_dt;

struct				s_arguments
{
	int				flgmods : 16;
	int				width;
	int				precision;
	int				char_count;
	char			conv;
}					arg;

/*
** Parsing
*/

void				master_pars(char *fmt, int *i);
int					flag_parse(char *str, int *i);
int					width_parser(char *str, int *i);
int					precision_parser(char *str, int *i);
int					lengthmod_pars(char *str, int *i);
int					conv_pars(char *fmt, int *i);

/*
** Parsing support functions
** Some of my parsers were a little too long...
*/

void				precbuild(char *str, int *i);
void				isshort(char *str, int *i);
void				islonglong(char *str, int *i);

/*
** Formatting
*/

char				*c_form(char orig);
void				s_form(char *orig);
void				p_form(char *orig);
void				dui_form(char *orig);

/*
** //will most likely be getting rid of all these
** /char	*insertplussign(char *str);
** /char	*lead_zero_negsign(char *dest, char *src);
** /char	*leading_zeros_spaces(char *dest, char *src, int arg_size);
** /char	*rj_strncpy(char *src);
** /char	*lj_strncpy(char *src);
*/

/*
** Checksign functions
*/

void				dui_sign(char *formstr, char *origstr);

/*
** Print functions
*/

void				prfree(char *res);

/*
** Struc functions
*/

void				reset_flags(void);
void				reset_members(void);
void				reset_struct(void);

#endif
