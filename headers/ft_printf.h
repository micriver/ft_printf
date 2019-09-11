/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 10:11:59 by mirivera          #+#    #+#             */
/*   Updated: 2019/09/11 16:22:43 by mirivera         ###   ########.fr       */
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

# define CONV_SPECS "scdiuoxXpf%"
# define SPECIAL_SPECS "$%*"
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
# define EXP_0 (11)

# define ZERO_FLAG CHECK_BIT(arg.flgmods, ZERO_F)
# define MINUS_FLAG CHECK_BIT(arg.flgmods, MINUS_F)
# define PLUS_FLAG CHECK_BIT(arg.flgmods, PLUS_F)
# define SHARP_FLAG CHECK_BIT(arg.flgmods, SHARP_F)
# define INVP_FLAG CHECK_BIT(arg.flgmods, INVP_F)
# define LONEDEC_F CHECK_BIT(arg.flgmods, LONEDEC)
# define EXP_0_F CHECK_BIT(arg.flgmods, EXP_0)

int					ft_printf(char *fmt, ...);
int					ft_printf_fd(int fd, char *fmt, ...);

/*
** Conversion
*/

void				conversion(int *i, char *str, va_list args);
void				specconversion(va_list args);
void				s_conv(va_list args);
void				c_conv(va_list args);
void				dui_conv(va_list args);
void				f_conv(va_list args);
void				o_conv(va_list args);
void				xbx_conv(va_list args);
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
	int				fd;
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
void				predec(char *str, int *i);

/*
** Formatting
*/

char				*c_form(char orig);
char				*per_form(char orig);
void				s_form(char *orig);
void				p_form(char *orig);
void				o_form(char *orig);
void				dui_form(char *orig);
void				xbx_form(char *origstr);

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
char				*plusf_check(char *formstr, char *origstr);
char				*invpf_check(char *formstr, char *origstr);

/*
** Checksign support functions
*/

/*
** functions checking flags for 'dui' conversion
** functions checking plus flag
*/

char				*pr_widch(char *formstr, char *origstr);
char				*under_pr(char *formstr);
char				*weird1ch(char *formstr);
char				*weird2ch(char *formstr);

/*
** functions checking invisible plus flag
*/

char				*ippr_widch(char *formstr, char *origstr);
char				*ipunder_pr(char *formstr);
char				*ipweird1ch(char *formstr);
char				*ipweird2ch(char *formstr);

/*
** functions supporting 'o' conversion
*/

void				o_pbuild(char *temp, char *origstr);
void				o_wstrbuild(char *origstr);

/*
** functions checking flags for 'o' conversion
*/

void				o_lonedecf(char *temp, char *origstr);
char				*o_explicitzero(char *temp, char *origstr);
void				o_ifminus(char *temp, char *origstr);
void				o_nominus(char *temp, char *origstr);

/*
** functions for 's' conversion
*/

char				*s_wbuild(char *temp, char *origstr);
void				s_widthhandle(char *temp, char *origstr);

/*
** functions for 'x' formatting
*/

char				*xbx_pbuild(char *origstr);
void				xbx_zero(char *temp, char *origstr);
char				*xbx_wstrbuild(char *temp);
void				xbx_zeroch2(char *temp, char *origstr);
void				xbx_zeroch3(char *temp, char *origstr);
void				xbx_nowid(char *temp, char *origstr, char *temp2);
char				*bx_zeroch(char *temp, char *origstr);
char				*xbx_prch(char *origstr, char *temp, char *temp2);

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
