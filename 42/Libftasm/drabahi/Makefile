# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: drabahi <drabahi@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/02/18 16:17:08 by drabahi           #+#    #+#              #
#    Updated: 2015/02/18 16:17:11 by drabahi          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libfts.a
TNAME = a.out

ASM = $(HOME)/.brew/bin/nasm

CFLAGS = -Wall -Werror -Wextra -I include/
AFLAGS = -f macho64
LFLAGS = -L. -lfts

HEADER = libfts.h

OPATH = obj
APATH = asm


AF = ft_bzero.s \
	ft_isalpha.s \
	ft_isdigit.s \
	ft_isalnum.s \
	ft_isascii.s \
	ft_isprint.s \
	ft_toupper.s \
	ft_tolower.s \
	ft_isupper.s \
	ft_islower.s \
	ft_puts.s \
	ft_putchar.s \
	ft_putstr.s \
	ft_strlen.s \
	ft_strcat.s \
	ft_memset.s \
	ft_memcpy.s \
	ft_strdup.s \
	ft_swap.s \
	ft_cat.s

CF = main.c \
	test_ft_bzero.c \
	test_ft_isstuff.c \
	test_ft_tostuff.c \
	test_ft_puts.c \
	test_ft_putchar.c \
	test_ft_putstr.c \
	test_ft_strlen.c \
	test_ft_strcat.c \
	test_ft_memset.c \
	test_ft_memcpy.c \
	test_ft_strdup.c \
	test_ft_swap.c \
	test_ft_cat.c


HFILES = $(patsubst %,include/%, $(HEADER))
OFILES = $(patsubst %.c,$(OPATH)/%.o, $(CF))
AFILES = $(patsubst %.s, $(OPATH)/%.o, $(AF))

all: $(OPATH) $(NAME)

$(NAME): $(AFILES)
	@ar rc $(NAME) $^
	@ranlib $(NAME)
	@echo "\033[33mCreation libfts\033[0m"

$(OPATH)/%.o: $(APATH)/%.s
	@$(ASM) $(AFLAGS) -O3 $< -o $@

clean:
	@rm -rf $(OPATH)
	@echo "\033[34mSuppression des .o\033[0m"

fclean: clean
	@rm -f $(NAME)
	@echo "\033[34mSuppression de libfts.a\033[0m"

re: fclean all

$(OPATH):
	@mkdir $(OPATH)


###		test		###

test: $(OPATH) $(TNAME)

$(TNAME): $(NAME) $(OFILES)
	@gcc -o $@ $(LFLAGS) $^
	@echo "\033[33mProjet compile\033[0m"

$(OPATH)/%.o: srcs/%.c include/test.h
	@gcc -o $@ -c $< $(CFLAGS)

test.clean:
	@rm -f $(OFILES)
	@echo "\033[34mSuppression des .o\033[0m"

test.fclean: test.clean
	@rm -f $(TNAME)
	@echo "\033[34mSuppression de $(TNAME)\033[0m"


test.re: test.fclean test


var:
	echo "== gcc =="
	$(CC) --version
	echo "== nasm =="
	$(ASM) -v
	echo "== CFLAGS =="
	echo $(CFLAGS)
	echo "== AFLAGS =="
	echo $(AFLAGS)
	echo "== headers =="
	echo $(HFILES)
	echo "== c files =="
	echo $(CF)
	echo $(OFILES)
	echo "== s files == "
	echo $(AF)
	echo $(AFILES)
