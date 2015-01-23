TARGET = bin/runner

#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build

#Options
CC = g++
SRC_EXT = .cpp
RM = rm -rf

#List classes here
CLASS = main\
		Map\
		Gui_mlx\
#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .h, $(addprefix $(INC_DIR)/, $(CLASS)))

#Flags
CFLAGS = -MM -Wall -Wextra -Werror -O3 -g -std=c++98
LFLAGS =

#Libs
LIB_LOCAL = ./lib/minilibx_macos/
LIB_GLOBAL = X11 Xext mlx
LIB_OTHER = -framework OpenGL -framework AppKit -L/usr/X11R6/lib
LIB += $(addprefix -L,$(LIB_LOCAL))
LIB += $(addprefix -l,$(LIB_GLOBAL))
LIB += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addprefix -I,$(LIB_LOCAL))
INC += -I/usr/X11R6/include

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
	@echo "\n\033[1;4;34mDEP:\033[0m\n"$<"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $(LIBS) $^ -o $@

$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT) $(DEP)
	@echo "\n\033[1;4;34mSRC:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m\n"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ): $(DEP)

#Tests
test:
	$(CC) $(CFLAGS) test/test.cpp $(INC) $(LIB) -o bin/test

