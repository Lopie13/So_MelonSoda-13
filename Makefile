# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmata-al <mmata-al@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 12:18:35 by mmata-al          #+#    #+#              #
#    Updated: 2024/06/06 21:19:58 by mmata-al         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRC_DIR				= srcs/
OBJ_DIR				= obj/
LIB_DIR				= libs/
LDFLAGS 			= -L./$(LIB_DIR)libft+ -lft
LIBFT				= ./$(LIB_DIR)libft+/libft.a

#Sources:
SOLONG	=	$(SRC_DIR)main.c \
		$(SRC_DIR)checkmap.c \
		$(SRC_DIR)cleaner.c \
		$(SRC_DIR)get_utils.c \
		$(SRC_DIR)gets.c \
		$(SRC_DIR)put_image-assets_utils.c \
		$(SRC_DIR)put_img_utils.c \
		$(SRC_DIR)utils.c \
		$(SRC_DIR)checkutils.c

GNL 	=	$(SRC_DIR)gnl/get_next_line_bonus.c \
		$(SRC_DIR)gnl/get_next_line_utils_bonus.c
						
SRCS = $(SOLONG) $(GNL)
OBJ = $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRCS))

CC = cc
CFLAGS = -Wall -Werror -Wextra -I$(LIBFT) -I$(SRC_DIR) -g
RM = rm -f

start:				
	@make all

$(LIBFT):
	@make -C ./libs/libft+/

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJ) $(LDFLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@$(RM) $(OBJ)
	@make clean -C ./$(LIB_DIR)/libft+

fclean: clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re: fclean all

.PHONY: start all clean fclean re