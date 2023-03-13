# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 09:45:46 by arabenst          #+#    #+#              #
#    Updated: 2023/03/13 10:01:31 by arabenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	024

SRCDIR		=	.

SRC			=	$(SRCDIR)/$(NAME).c

CC			=	gcc
CFLAGS		=	-Wall -Werror -Wextra

RM			=	rm
RMFLAGS		=	-rf

LIBFT_DIR	=	$(SRCDIR)/libft
LIBFT_LIB	=	libft.a
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

ARCS		=	$(LIBFT)

run: $(NAME)
	@./$(NAME)

$(NAME): $(LIBFT) $(SRC)
	$(CC) -o $(NAME) $(SRC) $(ARCS)

$(SRC):
	touch $(NAME).c

$(LIBFT):
	git clone https://github.com/aaron-22766/libft.git $(LIBFT_DIR); make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re