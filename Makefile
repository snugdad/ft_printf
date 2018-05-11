# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/26 19:11:26 by egoodale          #+#    #+#              #
#    Updated: 2018/05/10 19:43:02 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a 

CC =				gcc
FLAGS =				-Wall -Werror -Wextra

FT_SRC_DIR =		./libft
PRINTF_SRC_DIR =	./src

HEADER =			$(FT_SRC_DIR)libft.h
PRINTF_SRC_HEADER =	ft_printf.h

FT_COMPILED =		ft_wordcount.o\
		  ft_toupper.o\
		  ft_tolower.o\
		  ft_strtrim.o\
		  ft_strsplit.o\
		  ft_strstr.o\
		  ft_strsub.o\
		  ft_strrchr.o\
		  ft_strnstr.o\
		  ft_strnequ.o\
		  ft_strnew.o\
		  ft_strncpy.o\
		  ft_strndup.o\
		  ft_strncmp.o\
		  ft_strncat.o\
		  ft_strmap.o\
		  ft_strmapi.o\
		  ft_strlowcase.o\
		  ft_strlen.o\
		  ft_strlcat.o\
		  ft_strjoin.o\
		  ft_striter.o\
		  ft_striteri.o\
		  ft_strequ.o\
		  ft_strdup.o\
		  ft_strdel.o\
		  ft_strcpy.o\
		  ft_strcmp.o\
		  ft_strclr.o\
		  ft_strchr.o\
		  ft_strcat.o\
		  ft_str_is_uppercase.o\
		  ft_str_is_printable.o\
		  ft_str_is_numeric.o\
		  ft_str_is_lowercase.o\
		  ft_str_is_alpha.o\
		  ft_putstr.o\
		  ft_putstr_fd.o\
		  ft_putnbr.o\
		  ft_putnbr_fd.o\
		  ft_putendl.o\
		  ft_putendl_fd.o\
		  ft_putchar.o\
		  ft_putchar_fd.o\
		  ft_memset.o\
		  ft_memmove.o\
		  ft_memdel.o\
		  ft_memcpy.o\
		  ft_memchr.o\
		  ft_memcmp.o\
		  ft_memccpy.o\
		  ft_memalloc.o\
		  ft_lstnew.o\
		  ft_lstmap.o\
		  ft_lstiter.o\
		  ft_lstdel.o\
		  ft_lstdelone.o\
		  ft_lstadd.o\
		  ft_itoa.o\
		  ft_isprint.o\
		  ft_isdigit.o\
		  ft_isascii.o\
		  ft_isalpha.o\
		  ft_isalnum.o\
		  ft_intlen.o\
		  ft_bzero.o\
		  ft_atoi.o\
		  get_next_line.o\
		  ft_putnbr_unsigned.o\
		  ft_vector.o\
		  ft_realloc.o\
		  ft_recalloc.o\
		  ft_strzchr.o\
		  ft_imaxtoa.o\
		  ft_insert_str.o\
		  ft_str_to_unicode.o\
		  ft_wstrlen.o\
		  ft_wstrdup.o\
		  ft_wchrlen.o\
		  ft_wstr_to_str.o\
		  ft_uimaxtoa_base.o\
		  ft_str_toupper.o\
		  ft_strfill.o\

PRINTF_COMPILED =	check_mods.o\
					ft_printf.o \
                    handle_chr.o\
					handle_msc.o\
					handle_signed.o \
                    handle_strings.o\
					handle_unsigned.o\
					parse_args.o\
					parse_precision.o\
					parse_unsigned.o\
                    
COMPILED =			$(FT_COMPILED) $(PRINTF_COMPILED)

all: $(NAME)
	@mv *.o obj

$(NAME): $(COMPILED)
	@ar rc $(NAME) $(COMPILED)
	@ranlib $(NAME)
	@echo "made" $(NAME)

$(FT_COMPILED): %.o: $(FT_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) $< -o $@

$(PRINTF_COMPILED): %.o: $(PRINTF_SRC_DIR)/%.c
	@$(CC) -c $(FLAGS) -I $(FT_SRC_DIR) -I $(PRINTF_SRC_DIR) $< -o $@

clean:
	@-/bin/rm -f $(COMPILED)
	@echo "cleaned" $(NAME)

fclean: clean
	@-/bin/rm -f $(NAME)
	@echo "fcleaned" $(NAME)

re: fclean all
