# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mirivera <mirivera@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/06/04 18:42:05 by mirivera          #+#    #+#              #
#    Updated: 2019/09/04 15:18:29 by mirivera         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

HEADERS = headers/

CC = gcc

CFLAGS = -Wall -Werror -Wextra

SRCS = ft_printf.c \
	parser.c \
	reset_struct.c \
	supportfuncs.c \
	supportpars.c \
	cssupport.c \
	cssupport2.c \

CONV = conversion.c \
	specconversion.c \
	c_conv.c \
	s_conv.c \
	dui_conv.c \
	o_conv.c \
	xbx_conv.c \
	p_conv.c \
	f_conv.c \

FORM = c_form.c \
	s_form.c \
	p_form.c \
	dui_form.c \
	xbx_form.c \
	o_form.c \
	per_form.c \
	#f_form.c \

CKSIGN = dui_sign.c \
	invpf_check.c \
	plusf_check.c \

LIBFT_SRCS = ft_atoi.c \
	ft_bzero.c \
	ft_isalnum.c \
	ft_isalpha.c \
	ft_isascii.c \
	ft_isdigit.c \
	ft_isprint.c \
	ft_isspace.c \
	ft_itoa.c \
	ft_lstadd.c \
	ft_lstdel.c \
	ft_lstdelone.c \
	ft_lstiter.c \
	ft_lstmap.c \
	ft_lstnew.c \
	ft_memalloc.c \
	ft_memccpy.c \
	ft_memchr.c \
	ft_memcmp.c \
	ft_memcpy.c \
	ft_memdel.c \
	ft_memmove.c \
	ft_memset.c \
	ft_putchar.c \
	ft_putchar_fd.c \
	ft_putendl.c \
	ft_putendl_fd.c \
	ft_putnbr.c \
	ft_putnbr_fd.c \
	ft_putstr.c \
	ft_putstr_fd.c \
	ft_strcat.c \
	ft_strchr.c \
	ft_strclr.c \
	ft_strcmp.c \
	ft_strcpy.c \
	ft_strdel.c \
	ft_strdup.c \
	ft_strequ.c \
	ft_striter.c \
	ft_striteri.c \
	ft_strjoin.c \
	ft_strlcat.c \
	ft_strlen.c \
	ft_strmap.c \
	ft_strmapi.c \
	ft_strncat.c \
	ft_strncmp.c \
	ft_strncpy.c \
	ft_strndup.c \
	ft_strnequ.c \
	ft_strnew.c \
	ft_strnstr.c \
	ft_strrchr.c \
	ft_strsplit.c \
	ft_strstr.c \
	ft_strsub.c \
	ft_strtrim.c \
	ft_tolower.c \
	ft_toupper.c \
	get_next_line.c \
	ft_prefixchar.c \
	ft_prependchar.c \
	ft_srch_rep.c \
	ft_strrev.c \
   	ft_long_itoa.c \
	ft_ullitoa.c \
	ft_uitoa.c \
	ft_uitoa_base.c \
	ft_insertchar.c \
	ft_intputchar.c \
	ft_intputstr.c \
	ft_llitoa.c \
	ft_llitoa_base.c \
	ft_itoa_base.c \
	ft_itoa_base_up.c \
	ft_numlen.c \

OBJECTS = $(patsubst %.c,%.o,$(SRCS))
OBJECTS += $(patsubst %.c,%.o,$(LIBFT_SRCS))
OBJECTS += $(patsubst %.c,%.o,$(CONV))
OBJECTS += $(patsubst %.c,%.o,$(FORM))
OBJECTS += $(patsubst %.c,%.o,$(CKSIGN))

all: $(NAME)

$(NAME):
	@echo 'Compiling your source files...'
	@$(CC) $(CFLAGS) -c $(addprefix srcs/,$(SRCS)) $(addprefix libft/,$(LIBFT_SRCS)) $(addprefix conv/,$(CONV)) $(addprefix form/,$(FORM)) $(addprefix checksign/,$(CKSIGN)) -I $(HEADERS)
	@echo 'Building your library...'
	@ar rc $(NAME) $(OBJECTS)
	@echo 'Optimizing your library...'
	@ranlib $(NAME)
	@echo 'Library has been completed!'

clean:
	@echo 'Removing object files and any executables...'
	@rm -rf $(OBJECTS)
	@rm -rf a.out*
	@rm -rf debug*
	@rm -rf *.dysm

fclean:	clean
	@echo 'Removing the library...'
	@rm -rf $(NAME)

re:	fclean all
	@#echo 'Removing everything and then re-compiling...'

norme:
	@echo 'Le Norme...'
	@norminette -R CheckForbiddenSourceHeader $(HEADERS) $(addprefix srcs/,$(SRCS)) $(addprefix libft/,$(LIBFT_SRCS)) $(addprefix conv/,$(CONV)) $(addprefix form/,$(FORM))

debug:
	@echo 'Compiling your test executable...'
	@$(CC) $(CFLAGS) -g -I $(HEADERS) $(addprefix srcs/,$(SRCS)) $(addprefix conv/,$(CONV)) $(addprefix form/,$(FORM)) $(addprefix checksign/,$(CKSIGN)) ./misc_files/main.c ./libft/*.c -o debug_ft_printf -fsanitize=address 
	@echo 'debug_ft_printf executable created'
