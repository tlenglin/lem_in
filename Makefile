# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tlenglin <tlenglin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 15:25:21 by tlenglin          #+#    #+#              #
#    Updated: 2017/02/22 14:37:49 by tlenglin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			= lem-in
CC				= gcc
CFLAGS			= -Wall -Wextra -Werror
LIBFT   		= -Llibft -lft
LIBFT_PATH		= ./libft
INC_DIR			= includes/
ALGO_SRC		= breadth_first_search.c init_algo.c parallel_paths_search.c
TOOLS_SRC		= bonus.c free.c main.c malloc.c display.c display_paths.c
PARSING_SRC		= check_inputs.c check_inputs_bis.c get_inputs.c init_parsing.c
ALGO_OBJ		= $(ALGO_SRC:.c=.o)
TOOLS_OBJ		= $(TOOLS_SRC:.c=.o)
PARSING_OBJ		= $(PARSING_SRC:.c=.o)
VPATH			= srcs/parsing:srcs/algorithms:srcs/tools

########################
#    Makefile rules    #
########################
all: $(NAME)

# Executable
$(NAME): $(ALGO_OBJ) $(TOOLS_OBJ) $(PARSING_OBJ)
	@make -C libft
	@$(CC) -o $(NAME) $(CFLAGS) $^ -I $(INC_DIR) $(LIBFT)
	@echo "Compiling [$@]"

# Cleaning rules
clean:
	@rm -f $(ALGO_OBJ) $(TOOLS_OBJ) $(PARSING_OBJ)
	@make clean -C libft
	@echo "Cleaning [$(ALGO_OBJ) $(TOOLS_OBJ) $(PARSING_OBJ) libft]"

fclean: clean
	@rm -rf $(NAME)
	@make fclean -C libft
	@echo "Cleaning [lem-in]"

re: fclean all
.PHONY: clean fclean re libft
