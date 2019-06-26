# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tdumouli <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/08 16:51:40 by tdumouli          #+#    #+#              #
#    Updated: 2019/06/26 16:50:42 by tdumouli         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

ifeq ($(HOSTTYPE),)
	HOSTTYPE := $(shell uname -m)_$(shell uname -s)
endif

AUTEUR = "tdumouli"
NAMEI =
NAME = libft_malloc_$(HOSTTYPE).so
OBJDIR = ./objet
SRCDIR = ./src
INCDIR = -I./include -I./libft/include


MALLOC = free.o malloc.o page.o realloc.o show_mem.o calloc.o fct_ut.o
LIB = libft/libft.a

OBJ =	$(addprefix $(OBJDIR)/, $(MALLOC))

debugg = 

############################## normaly no change ###############################


NO_COLOR="\x1b[39m"
RED="\x1b[31m"
GREEN="\x1b[32m"
YELLOW="\x1b[33m"
CC = gcc
CFLAGS = $(INCDIR) -Wall -Wextra -Werror
DEBU = -fno-omit-frame-pointer -g
#-fsanitize=address -fno-omit-frame-pointer -g3
MAKE = /usr/bin/make

LSTDIR=	$(addprefix $(OBJDIR)/, $(LSTDIRI)) \

ifneq ($(NAMEI), )
all: objdir $(NAMEI)
	@echo $(GREEN)"compilation reussi"$(NO_COLOR)
else
all: objdir $(NAME)
	@echo $(GREEN)"compilation reussi cpl"$(NO_COLOR)
endif

objdir:
	@if ! [ -d $(OBJDIR) ]; then\
		mkdir $(OBJDIR) $(LSTDIR);\
	fi

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@
	@echo $(GREEN)$@" compile"$(NO_COLOR)

$(NAMEI): $(OBJ)
	@ar cr $(NAME) $(OBJ)
	@ranlib $(NAME)
	@echo $(GREEN)"library compile"$(NO_COLOR)

$(LIB) :
	$(MAKE) -C ./libft

$(NAME): $(LIB) $(OBJ)
	$(CC) $(OBJ) ./$(LIB) -o $(NAME) $(DEBUG) -shared
	rm -f libft_malloc.so
	ln -s $(NAME) libft_malloc.so
	@echo $(GREEN)$(NAME)" a ete cree"$(NO_COLOR)

clean:
	@$(MAKE) clean -C libft
	@rm -rf $(OBJ)
	@$(MAKE) cleanv

ifeq ($(shell find . -type f | grep "\.o"), )
cleanv:
	@echo $(GREEN)"les objets sont clean"$(NO_COLOR)
else
cleanv:
	@echo $(RED)"il ya probleme"
	@echo $(YELLOW)$(shell echo | find . -type f | grep "\.o" | cat -e)
	exit
endif

cl:
	@if [ "test" = "test" ]; then\
		echo "Hello world";\
	fi

auteur:
	@echo $(AUTEUR) > auteur
	@echo $(GREEN)"le fichier auteur a bien ete cree"$(NO_COLOR)

fclean: clean
	@$(MAKE) fclean -C ./libft
	@rm -f $(NAME) $(NAMELIB) libft_malloc.so
	@echo $(GREEN)"tout est clean"$(NO_COLOR)

re: fclean all

.PHONY: all clean fclean re cleanv anc
