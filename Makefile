# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apple <apple@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 17:11:47 by apple             #+#    #+#              #
#    Updated: 2025/04/01 16:36:43 by apple            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

SRC = pipex.c \
helpers.c \
free_funcs.c \
commands_validation.c \
create_pipe.c \
find_cmd.c

OBJS = $(SRC:.c=.o)

NAME = pipex

LIBFT_PATH = libft

LIBFT_NAME = libft.a

$(NAME): $(OBJS)
	@make -C $(LIBFT_PATH) --no-print-directory
	@$(CC) $(CFLAGS) $(OBJS) -g -L$(LIBFT_PATH) -lft -o $(NAME)
	@echo "Compilation completed successfully."

all: $(NAME)

clean:
	@make clean -C $(LIBFT_PATH) --no-print-directory
	@$(RM) $(OBJS)
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: re clean make