##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## Makefile
##

SRC	=	 my_char_isnum.c 		\
		 my_strncmp.c 			\
		 my_int_swap.c			\
		 my_putchar.c 			\
		 my_sort_int_array.c 		\
		 my_strstr.c 			\
		 my_compute_power_rec.c 	\
		 my_strcapitalize.c 		\
		 my_getnbr.c 			\
		 my_putstr.c 			\
		 my_strupcase.c 		\
		 my_strncat.c 			\
		 my_strcat.c 			\
		 my_str_isalpha.c 		\
		 my_strlen.c 			\
		 my_isneg.c 			\
		 my_str_isnum.c 		\
		 my_strncpy.c 			\
		 my_strcpy.c 			\
		 my_strlowcase.c 		\
		 my_showmem.c 			\
		 my_str_isupper.c 		\
		 my_revstr.c 			\
		 my_str_islower.c 		\
		 my_find_prime_sup.c 		\
		 my_char_isalpha.c 		\
		 my_strcmp.c 			\
		 my_put_nbr.c 			\
		 my_compute_square_root.c	\
		 my_is_prime.c 			\
		 my_error.c 		\
		 my_str_isprintable.c		\
		 my_str_to_word_array.c		\
		 my_show_word_array.c 		\
		 my_calloc_char.c		\
		 my_memset_char.c		\
		 my_calloc_int.c		\
		 my_memset_int.c		\
		 my_strdup.c			\
		 my_printf.c			\
		 my_put_unsigned.c		\
		 my_int_to_unsigned.c		\
		 my_putnbr_base.c		\
		 my_putstr_unprintable.c	\
		 my_putchar_unprintable.c	\
		 my_put_ptr.c \
		 my_open_and_read.c \
		 my_close_file.c \
		 my_nbr_size.c	\
		 my_strndup.c \
		 my_putstr_error.c \
		 my_calloc_two_d_array.c \
		 my_print_char_two_d_array.c \
		 my_char_array_dup.c



OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	cp $(NAME) ../
	cp my.h ../../include/

clean:
	rm $(OBJ)

fclean:	clean
	rm ../$(NAME)
	rm $(NAME)

re: fclean all
