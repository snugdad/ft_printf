NAME = printf
SRC = src/main.c src/ft_printf.c src/handle_integer.c src/pf_handle.c src/check_mods.c src/handle_strings.c src/handle_chr.c src/handle_hexadec.c src/handle_msc.c
OBJ = $(patsubst %.c, %.o, *.c)
INCL = ft_printf.h
CFLAGS = -g3
LIB = libft/libft.a
BUILD = build
all: $(NAME)
	
$(NAME): $(OBJ) $(SRC)
	gcc $(CFLAGS) $(OBJ) -o $(NAME) $(LIB)
	mkdir $(BUILD) && mv $(OBJ) $(BUILD)
$(OBJ):
	gcc -I $(INCL) $(CFLAGS) $(SRC) -c 

clean:
	rm -rf $(BUILD)
fclean: clean
	rm -f $(NAME)
re: fclean all
	
