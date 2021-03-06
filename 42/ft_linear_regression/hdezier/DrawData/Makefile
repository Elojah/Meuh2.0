# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 16:44:06 by leeios            #+#    #+#              #
#    Updated: 2016/09/05 20:18:24 by hdezier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = draw_data

#Directories
BIN_DIR = bin
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR =

#Options
UNAME := $(shell uname)

ifeq ($(UNAME), Linux)
	# do something Linux-y
	CC = clang++-3.6
endif

ifeq ($(UNAME), Darwin)
	# do something Darwin-y
	CC = clang++
endif

SRC_EXT = .cpp
RM = rm -rf

#List classes here
CLASS = main\
		SDL_linear\

#List interfaces here
INTERFACE = \

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))

#Flags
CFLAGS = -Wall -Wextra -Werror\
		-fno-unwind-tables -fno-rtti\
		-O3\
		-std=c++11\

LFLAGS =

#Libs
LIB_LOCAL = \

LIB_GLOBAL = \

LIB_OTHER = `util/SDL2-2.0.4/build/sdl2-config --cflags --libs`\

LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))
INC += -Iutil/SDL2-2.0.4/include -I../include

SDL_DIR = util/SDL2-2.0.4

#RULES
all : make_sdl dirbin $(BIN_DIR)/$(TARGET)

make_sdl :
	if [ -d "./util/SDL2-2.0.4" ]; then \
		echo "Library directory already exists";\
	else\
		echo "Extract and compile SDL" &&\
		cd util &&\
		tar -xzf SDL2-2.0.4.tar.gz &&\
		cd SDL2-2.0.4 &&\
		mkdir build &&\
		cd build &&\
		CC=../build-scripts/gcc-fat.sh ../configure --prefix=`pwd` &&\
		make &&\
		make install;\
	fi

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET) $(BIN_DIR) $(SDL_DIR)

re : fclean all

dirbin:
	mkdir -p $(BIN_DIR)

.PHONY: all clean fclean re

.SILENT: dirlib dirbuild dirbin make_sdl

#Build rule
$(BIN_DIR)/$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mLINK:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)
	@ln -sf $(BIN_DIR)/$(TARGET) $(TARGET)

#Compilation rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "\n\033[1;4;34mCOMPILE:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

-include $(DEP)
