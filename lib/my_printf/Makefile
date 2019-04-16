##
## EPITECH PROJECT, 2018
## first makefile
## File description:
## myfirst makefile
##

NAME	=	libprintf.a

SRC	=	my_printf.c	\
		normal_print/my_putchar.c	\
		normal_print/my_putfchar.c	\
		normal_print/my_put_nbr.c	\
		normal_print/my_put_nbr_oct.c	\
		normal_print/my_put_nbr_dec.c	\
		normal_print/my_put_nbr_hexadec.c	\
		normal_print/my_putstr.c	\
		normal_print/my_putstr_mod.c	\
		normal_print/my_put_nbr_bin.c	\
		right_print/my_rightchar.c	\
		right_print/my_rightstr.c	\
		right_print/my_rightstr_mod.c	\
		right_print/my_right_nbr.c	\
		right_print/my_right_nbr_oct.c	\
		right_print/my_right_nbr_dec.c	\
		right_print/my_right_nbr_hexadec.c	\
		right_print/my_right_nbr_bin.c	\
		left_print/my_leftchar.c	\
		left_print/my_left_nbr.c	\
		left_print/my_left_nbr_dec.c	\
		left_print/my_left_nbr_hexadec.c	\
		left_print/my_left_nbr_oct.c	\
		left_print/my_left_nbr_bin.c	\
		left_print/my_leftstr.c	\
		left_print/my_leftstr_mod.c	\
		my_getnbr.c	\
		my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

lib:	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mv $(NAME) ../$(NAME)

test:
	gcc main.c -L . -l my -W -Wall -Wextra -Werror -o test

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f ../$(NAME)

re:	fclean lib
