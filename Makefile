# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: alraltse <alraltse@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 17:11:47 by apple             #+#    #+#              #
#    Updated: 2025/04/11 15:02:02 by alraltse         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

SRC = src/pipex.c \
src/helpers.c \
src/helpers_2.c \
src/free_funcs.c \
src/commands_validation.c \
src/create_pipe.c \
src/find_flags.c

OBJS = $(SRC:.c=.o)

NAME = pipex

LIBFT_PATH = libft

LIBFT_NAME = libft.a

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS) -g -L$(LIBFT_PATH) -lft -o $(NAME)
	@echo "Compilation completed successfully."

all: $(NAME)

clean:
	@make clean -s -C $(LIBFT_PATH)
	@$(RM) $(OBJS)
	@echo "Object files removed."

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	@echo "Executable removed."

re: fclean all

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus bonus_re
