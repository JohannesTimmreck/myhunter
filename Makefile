##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## hunter
##
SRC	=	main.c	\
		set_stuff.c	\
		int_to_str.c	\
		destroy_stuff.c	\
		duck.c	\
		lives_and_score.c	\
		manage_events.c	\
		start_screen.c	\
		end_screen.c	\
		set_destroy_endscreen.c	\
		set_background.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_hunter

CC	=	gcc

CFLAGS	+=	-g

all:	$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my_printf
		$(CC) -o $(NAME) -W -Wall -Wextra -Werror $(OBJ) -l csfml-graphics -l csfml-system -lm -L lib -l printf
clean:
	rm -f $(OBJ)
	make clean -C lib/my_printf

fclean:	clean
	make fclean -C lib/my_printf
	rm -f $(NAME)

re:	fclean all
