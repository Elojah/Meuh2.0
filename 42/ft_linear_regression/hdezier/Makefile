# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: hdezier <hdezier@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/05/14 16:44:06 by leeios            #+#    #+#              #
#    Updated: 2016/08/10 22:47:50 by hdezier          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

TARGET = ft_linear_regression

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
		CsvLineParser\
		LinearRegression2D\

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

LIB_OTHER = -Lutil/ogdf\
			-lOGDF\
			-lCOIN\

LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))
INC += -Iutil/ogdf/include

OGDF_DIR = "util/ogdf"

#RULES
all : make_lib dirbin $(BIN_DIR)/$(TARGET)

make_lib :
	mkdir -p util
	if [ ! -d "./$(OGDF_DIR)" ];then						\
		cd util												\
		&& git clone https://github.com/ogdf/ogdf			\
		&& cd ogdf											\
		&& cmake .											\
		&& make -j8;										\
	fi

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET) $(BIN_DIR)

re : fclean all

dirbin:
	mkdir -p $(BIN_DIR)

.PHONY: all clean fclean re

.SILENT: dirlib dirbuild dirbin make_lib

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
