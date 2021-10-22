# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ivloisy <ivloisy@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/08 16:55:50 by ivloisy           #+#    #+#              #
#    Updated: 2021/10/22 00:41:50 by ivloisy          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = gcc

FLAG = -Wall -Werror -Wextra

SRCDIR = sources

SRC = ./$(SRCDIR)/push_swap.c \
		./$(SRCDIR)/parsing.c \
		./$(SRCDIR)/exit_error.c \
		./$(SRCDIR)/swap.c \
		./$(SRCDIR)/push.c \
		./$(SRCDIR)/rotate.c \
		./$(SRCDIR)/reverse_rotate.c \
		./$(SRCDIR)/sort.c \
		./$(SRCDIR)/simplification.c \
		./$(SRCDIR)/test_display.c

BON = ./$(SRCDIR)/checker_bonus.c

HDR = ./$(SRCDIR)/push_swap.h

OBJDIR = objects

BOBDIR = objects_bonus

OBJ = $(OBJDIR)/*.o

BOB = $(BOBDIR)/*.o

LFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(LFT) $(OBJ)
	@echo "\033[36m\n$(NAME) creation\t\t\t\t🧱\n"
	$(CC) $(FLAG) -o $@ $+
	@echo "\033[35m\n$(NAME) has been created with success !\t🌈\n"

$(OBJ): $(SRC) $(HDR)
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(SRC)
	mkdir -p $(OBJDIR)
	mv *.o $(OBJDIR)

$(LFT): ./libft/*.c ./libft/*.h
	make -C libft/
	make -C libft/ bonus
	make -C libft/ utils

bonus: $(BONUS)

$(BONUS): $(LFT) $(BOB)
	@echo "\033[36m\n$@ creation\t\t\t\t🧱\n"
	$(CC) $(FLAG) -o $@ $+
	@echo "\033[35m\n$@ has been created with success !\t\tmak🌈\n"

$(BOB): $(BON) $(HDR)
	@echo "\033[32m\nSources files compilation\t\t\t⚙️\n"
	$(CC) $(FLAG) -c $(BON)
	mkdir -p $(BOBDIR)
	mv *.o $(BOBDIR)

clean:
	@echo "\033[33m\nRemove objects files\t\t--->\t\t🗑\n"
	rm -rf $(OBJDIR) $(BOBDIR)
	make -C libft/ clean

fclean: clean
	@echo "\033[33m\nRemove $(NAME) file\t\t--->\t\t🗑\n"
	rm -f $(NAME) $(BONUS)
	make -C libft/ fclean

re: fclean all

.PHONY: all clean fclean re bonus

#-g3 -fsanitize=address 