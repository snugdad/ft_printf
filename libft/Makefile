# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: egoodale <egoodale@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/02/21 11:46:19 by egoodale          #+#    #+#              #
#    Updated: 2018/05/10 15:34:34 by egoodale         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libft.a
CFLAGS	=	-Wall -Werror -Wextra -I includes -c

FILES 	= ft_wordcount.c \
		  ft_toupper.c \
		  ft_tolower.c \
		  ft_strtrim.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strrchr.c \
		  ft_strnstr.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strncpy.c \
		  ft_strndup.c \
		  ft_strncmp.c \
		  ft_strncat.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strlowcase.c \
		  ft_strlen.c \
		  ft_strlcat.c \
		  ft_strjoin.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strequ.c \
		  ft_strdup.c \
		  ft_strdel.c \
		  ft_strcpy.c \
		  ft_strcmp.c \
		  ft_strclr.c \
		  ft_strchr.c \
		  ft_strcat.c \
		  ft_strfill.c \
		  ft_str_is_uppercase.c \
		  ft_str_is_printable.c \
		  ft_str_is_numeric.c \
		  ft_str_is_lowercase.c \
		  ft_str_is_alpha.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_memset.c \
		  ft_memmove.c \
		  ft_memdel.c \
		  ft_memcpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memccpy.c \
		  ft_memalloc.c \
		  ft_lstnew.c \
		  ft_lstmap.c \
		  ft_lstiter.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstadd.c \
		  ft_itoa.c \
		  ft_isprint.c \
		  ft_isdigit.c \
		  ft_isascii.c \
		  ft_isalpha.c \
		  ft_isalnum.c \
		  ft_intlen.c \
		  ft_bzero.c \
		  ft_atoi.c\
		  get_next_line.c\
		  ft_putnbr_unsigned.c\
		  ft_vector.c\
		  ft_realloc.c\
		  ft_recalloc.c\
		  ft_strzchr.c\
		  ft_imaxtoa.c\
		  ft_insert_str.c\
		  ft_str_to_unicode.c\
		  ft_wstrlen.c\
		  ft_wstrdup.c\
		  ft_wchrlen.c\
		  ft_wstr_to_str.c\
		  ft_uimaxtoa_base.c\
		  ft_str_toupper.c\

OBJ		= $(patsubst %.c, %.o, $(FILES))  

all: $(NAME)
		
$(NAME):	
		@gcc $(CFLAGS) $(FILES)
		@ar rcs $(NAME) $(OBJ)
		@ranlib $(NAME)

clean:
		@rm -f $(OBJ)

fclean: clean
		@rm -f $(NAME)

re: fclean all
