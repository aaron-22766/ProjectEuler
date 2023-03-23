# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabenst <arabenst@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 09:45:46 by arabenst          #+#    #+#              #
#    Updated: 2023/03/23 10:39:02 by arabenst         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	030

PRE			=	$(shell echo $(NAME)-1 | bc)
PREV		=	$(shell printf "%03d" $(PRE))

SRCDIR		=	.
SRC			=	$(SRCDIR)/$(NAME).c

CC			=	gcc
CFLAGS		=	-Wall -Wextra -Werror

RM			=	rm
RMFLAGS		=	-rf

LIBFT_DIR	=	$(SRCDIR)/libft
LIBFT_LIB	=	libft.a
LIBFT		=	$(LIBFT_DIR)/$(LIBFT_LIB)

ARCS		=	$(LIBFT)

run: $(NAME)
	@./$(NAME)

$(NAME): $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) -o $(NAME) $(SRC) $(ARCS)

$(SRC):
	$(RM) $(RMFLAGS) $(PREV)
	mv $(PREV).c ./solved
	cp template.c $(NAME).c

$(LIBFT):
	git clone https://github.com/aaron-22766/libft.git $(LIBFT_DIR); make -C $(LIBFT_DIR)

all: $(NAME)

clean:
	make -C $(LIBFT_DIR) clean

fclean: clean
	$(RM) $(RMFLAGS) $(NAME)
	make -C $(LIBFT_DIR) fclean

libclean: fclean
	$(RM) $(RMFLAGS) $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re