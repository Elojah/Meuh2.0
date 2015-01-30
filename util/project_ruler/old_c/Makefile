TARGET = bcp

#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib

#Options
CC = gcc
SRC_EXT = .c
RM = rm -rf

#List classes here
FILES = main\
		init_ncurse\
		menu\
#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(FILES)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(FILES)))

#Flags
CFLAGS = -Wall -Wextra -Werror -O3 -g
LFLAGS =

#Libs
LIB_LOCAL =
LIB_GLOBAL = ncurses
LIB_OTHER =
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
	@echo "\n\033[1;4;34mDEP:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@echo "\n\033[1;4;34mSRC:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

