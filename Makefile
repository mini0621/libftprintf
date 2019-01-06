NAME = libftprintf.a

CC = gcc 

FLAGS = -Wall -Werror -Wexra

INCLUDES = .


SRC = ft_printf.c ft_lltoa.c ft_dltoa.c convertion.c errors.c libftprintf.h process_csp.c process_flag.c process_douxX.c setting.c process_eg.c process_f.c 
OBJ = $(SRC:.c=.o)

.PHONY: all fclean clean $(NAME)

RM = rm -f 

$(NAME):
	make -C libft/ fclean
	make -C libft/ re
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCLUDES)
	ar rc  $(NAME) $(OBJ)
all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
