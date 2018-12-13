# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile Template                                  :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mnishimo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/21 08:40:41 by mnishimo          #+#    #+#              #
#    Updated: 2018/12/12 09:09:47 by mnishimo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# name of the program you want to make 
NAME =

CC = gcc 

FLAGS = -Wall -Werror -Wexra

# where the linking files are 
INCLUDES = .


SRC =
OBJ = $(SRC:.c=.o)

RM = rm -f 

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC) -I $(INCLUDES)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all
