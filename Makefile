# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apple <apple@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 17:11:47 by apple             #+#    #+#              #
#    Updated: 2025/04/07 16:56:34 by apple            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

SRC = mandatory_src/pipex.c \
mandatory_src/helpers.c \
mandatory_src/helpers_2.c \
mandatory_src/free_funcs.c \
mandatory_src/commands_validation.c \
mandatory_src/create_pipe.c \
mandatory_src/find_cmd.c \
mandatory_src/find_flags.c

BONUS_SRC = bonus_src/pipex_bonus.c \
bonus_src/add_cmds_to_arr.c \
bonus_src/free.c \
bonus_src/helpers.c \
bonus_src/helpers_2.c \
bonus_src/add_args_to_arr.c \
bonus_src/create_pipe_bonus.c

OBJS = $(SRC:.c=.o)

BONUS_OBJS = $(BONUS_SRC:.c=.o)

NAME = pipex

BONUS_NAME = pipex_bonus

LIBFT_PATH = libft

LIBFT_NAME = libft.a

$(NAME): $(OBJS)
	@make -s -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(OBJS) -g -L$(LIBFT_PATH) -lft -o $(NAME)
	@echo "Compilation completed successfully."

all: $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@make -s -C $(LIBFT_PATH)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -g -L$(LIBFT_PATH) -lft -o $(BONUS_NAME)
	@echo "Bonus compiled successfully."

bonus: $(BONUS_NAME)

clean:
	@make clean -s -C $(LIBFT_PATH)
	@$(RM) $(OBJS)
	@echo "Object files removed."
	
clean_bonus:
	@make clean -s -C $(LIBFT_PATH)
	@$(RM) $(BONUS_OBJS)
	@echo "Bonus object files removed."

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	@echo "Executable removed."

fclean_bonus: clean_bonus
	@$(RM) $(BONUS_NAME)
	@$(RM) $(LIBFT_PATH)/$(LIBFT_NAME)
	@echo "Bonus executable removed."

re: fclean all

bonus_re: fclean_bonus bonus

.PHONY: all clean fclean re bonus clean_bonus fclean_bonus bonus_re
