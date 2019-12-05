# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 20:45:25 by bkayleen          #+#    #+#              #
#    Updated: 2019/12/05 13:33:19 by bkayleen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = src/main.c \
	  src/parser.c \
	  src/parse_flags.c \
	  src/show_usage.c

LIB = libft
OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	make -C $(LIB)
	gcc $(OBJ) -o $(NAME) -L$(LIB) -lft

%.o: %.c
	gcc -I includes -c -Wall -Wextra -Werror $< -o $@

clean:
	make -C $(LIB) clean 
	/bin/rm -f src/*.o

fclean: clean
	make -C $(LIB) fclean
	/bin/rm -f $(NAME)

re: fclean all
