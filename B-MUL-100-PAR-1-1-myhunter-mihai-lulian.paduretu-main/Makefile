##
## EPITECH PROJECT, 2023
## Makefile
## File description:
## Makefile for MyHunter
##

SRC	=	my_huntertitle.c\
		my_huntertitlestart.c\
		h_option.c\
		main.c\
		music.c\
		game_window.c\
		duck_logic.c\
		game_screen.c\
		mini_printf.c\
		my_put_nbr.c\
		my_putstr.c\
		my_putchar.c\
		my_strcpy.c\
		my_strlen.c

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

SFML_LIB	=	-lcsfml-graphics -lcsfml-window\
			-lcsfml-system -lcsfml-audio -lm

all: $(NAME)

$(NAME): $(OBJ)
	gcc -o $(NAME) $(OBJ) $(SFML_LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
