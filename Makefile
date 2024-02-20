# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lucas <lucas@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/15 15:59:30 by lumaret           #+#    #+#              #
#    Updated: 2024/02/20 13:04:31 by lucas            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME				= push_swap

LIBFT				= ./libft/libft.a
PRINTF				= ./ft_printf/
INC					= includes/
SRC_DIR				= srcs/
OBJ_DIR				= obj/

CC					= gcc
CFLAGS				= -Wall -Werror -Wextra -I
RM					= rm -f

COMMANDS_DIR		=	$(SRC_DIR)commands/push.c \
						$(SRC_DIR)commands/rev_rotate.c \
						$(SRC_DIR)commands/rotate.c \
						$(SRC_DIR)commands/sort_stacks.c \
						$(SRC_DIR)commands/sort_three.c \
						$(SRC_DIR)commands/swap.c

PUSH_SWAP_DIR		=	$(SRC_DIR)push_swap/error.c \
						$(SRC_DIR)push_swap/a_2_b.c \
						$(SRC_DIR)push_swap/b_2_a.c \
						$(SRC_DIR)push_swap/push_swap.c \
						$(SRC_DIR)push_swap/split.c \
						$(SRC_DIR)push_swap/stack_init.c \
						$(SRC_DIR)push_swap/tools.c

PRINTD_DIR			=	$(SRC_DIR)ft_printf/ft_handlechar.c \
						$(SRC_DIR)ft_printf/ft_handlenbr.c \
						$(SRC_DIR)ft_printf/ft_handleptr.c \
						$(SRC_DIR)ft_printf/ft_printf.c
			
SRCS 				= $(COMMANDS_DIR) $(PUSH_SWAP_DIR) $(PRINTD_DIR)

$(OBJ_DIR)%.o:		$(SRC_DIR)%.c 
					@mkdir -p $(@D)
					@$(CC) $(CFLAGS) $(INC) -c $< -o $@

OBJ 				= $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

start:				
					@make all

$(LIBFT):
					@make -C ./libft

all: 				$(NAME)

$(NAME): 			$(OBJ) $(LIBFT)
					@$(CC) $(CFLAGS) $(INC) $(OBJ) $(LIBFT) $(PRINTF) -o $(NAME)


clean:
					@$(RM) -r $(OBJ_DIR)
					@make clean -C ./libft

fclean: 			clean
					@$(RM) $(NAME)
					@$(RM) $(LIBFT)

re: 				fclean all

.PHONY: 			start all clean fclean re