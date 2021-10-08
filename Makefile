# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 16:55:50 by ivloisy           #+#    #+#              #
#    Updated: 2021/10/08 17:23:07 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = gcc

FLAG = -Wall -Werror -Wextra

SRCDIR = sources

SRC = ./$(SRCDIR)/main.c

HDR = ./$(SRCDIR)/

OBJDIR = objects

OBJ = $(OBJDIR)/*.o

LFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LFT) $(OBJ)
	@echo "\033[36m\n$(NAME) creation\t\t\t\t🧱\n"
	clang $(FLAG) -o $@ $+ -L minilibx/ -l X11 -l Xext -l m -l bsd -l mlx
	@echo "\033[35m\n$(NAME) has been created with success !\t\t🌈\n"

$(OBJ): $(SRC) $(HDR)
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(SRC)
	mkdir -p $(OBJDIR)
	mv *.o $(OBJDIR)

$(LFT): ./libft/*.c ./libft/*.h
	make -C libft/

clean:
	@echo "\033[33m\nRemove objects files\t\t--->\t\t🗑\n"
	rm -rf $(OBJDIR)
	make -C libft/ clean

fclean: clean
	@echo "\033[33m\nRemove $(NAME) file\t\t--->\t\t🗑\n"
	rm -f $(NAME)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re