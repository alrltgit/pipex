# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apple <apple@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 17:11:47 by apple             #+#    #+#              #
#    Updated: 2025/03/29 17:26:35 by apple            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -f

FLAGS = -Wall -Wextra -Werror -g

SRC = pipex.c

OBJS = $(SRC:.c=.o)

NAME = pipex

LIBFT_PATH = libft

LIBFT_NAME = libft.a

$(NAME): $(OBJS)
	make -C $(LIBFT_PATH)
	$(CC) $(FLAGS) $(OBGS) -L$(LIBFT_PATH) -lft -o $(NAME)

all: $(NAME)

clean:
	make clean -C $(LIBFT_PATH)
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)
	$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)

re: fclean all

.PHONY: re clean make