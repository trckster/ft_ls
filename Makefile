# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bkayleen <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/20 20:45:25 by bkayleen          #+#    #+#              #
#    Updated: 2020/01/22 23:37:05 by bkayleen         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRC = src/main.c \
	  src/parser.c \
	  src/parse_flags.c \
	  src/parse_files.c \
	  src/messages.c \
	  src/ls.c \
	  src/crawler.c \
	  src/display.c \
	  src/files_helpers.c \
	  src/flags_helpers.c \
	  src/stat.c \
	  src/recursive.c \
	  src/free.c \
	  src/count_helpers.c \
	  src/sort.c \
	  src/errors.c \
	  src/indentations.c \
	  src/indentations_builder.c

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
