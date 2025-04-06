# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apple <apple@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/29 17:11:47 by apple             #+#    #+#              #
#    Updated: 2025/04/06 22:50:56 by apple            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc

RM = rm -f

CFLAGS = -Wall -Wextra -Werror -g

SRC = pipex.c \
helpers.c \
helpers_2.c \
free_funcs.c \
commands_validation.c \
create_pipe.c \
find_cmd.c \
find_flags.c

BONUS_SRC = bonus/pipex.c \
bonus/add_cmds_to_arr.c \
bonus/free.c

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
