TARGET = bin/runner

#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib

#Options
CC = g++
SRC_EXT = .cpp
RM = rm -rf

#List classes here
CLASS = main\
		Map\
		IGui_mlx\

#List interfaces here
INTERFACE = IGui\
			IEventHandler\

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .h, $(addprefix $(INC_DIR)/, $(CLASS)))
LIBS = $(addprefix -L,$(LIB_DIR))

#Flags
CFLAGS = -MMD -Wall -Wextra -Werror -O3 -g -std=c++98
LFLAGS =

#Libs
LIB_LOCAL = /usr/X11R6 ./lib/minilibx_macos
LIB_GLOBAL = mlx Xext X11
LIB_OTHER = -framework OpenGL -framework AppKit
LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))

#RULES
all : dirbuild $(TARGET)

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET)

re : fclean all

dirbuild:
	mkdir -p build

.PHONY: all clean fclean re dirbuild

.SILENT: dirbuild

#Build rules
$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mDEP:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT) $(DEP)
	@echo "\n\033[1;4;34mSRC:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m\n"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ): $(DEP)

#Tests
test:
	$(CC) $(CFLAGS) test/test.cpp $(INC) $(LIBS) -o bin/test

