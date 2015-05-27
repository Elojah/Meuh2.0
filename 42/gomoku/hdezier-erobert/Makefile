TARGET = bin/gomoku

#Directories
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
LIB_DIR = lib

#Options
CC = clang++
SRC_EXT = .cpp
RM = rm -rf

#List classes here
CLASS = main\
		Cell\
		Board\
		UserInterface\
		Player\
		Rules\
		GameManager\

#List interfaces here
INTERFACE = \

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .d, $(addprefix $(BUILD_DIR)/, $(CLASS)))

#Flags
CFLAGS =-MMD -Wall -Wextra -Werror -O3 -std=c++98 -Wno-unused-parameter
LFLAGS =

#Libs
PWD = $(shell pwd)
ASFML = SFML-2.2-osx-clang-universal
DSFML = $(LIB_DIR)/sfml

LIB_LOCAL = \
			./$(DSFML)\

LIB_GLOBAL = \
			sfml-graphics\
			sfml-window\
			sfml-system\

LIB_OTHER = \
			-rpath $(PWD)/$(DSFML)/lib/\

LIBS += $(addsuffix /lib, $(addprefix -L, $(LIB_LOCAL)))
LIBS += $(addprefix -l,$(LIB_GLOBAL))
LIBS += $(LIB_OTHER)

#Includes
INC += $(addprefix -I,$(INC_DIR))
INC += $(addsuffix /include, $(addprefix -I, $(LIB_LOCAL)))

#RULES
all : dirbin $(DSFML) $(TARGET)

clean :
	$(RM) $(BUILD_DIR)

fclean :
	$(RM) $(BUILD_DIR) $(TARGET)
	$(RM) $(DSFML)

re : fclean all

$(DSFML):
	curl -L -O -# --progress-bar  http://www.sfml-dev.org/files/$(ASFML).tar.gz
	tar -xf $(ASFML).tar.gz
	mv $(ASFML) $(DSFML)
	cd $(DSFML)/Frameworks/ && ln -s ../extlibs/freetype.framework
	cd $(DSFML)/Frameworks/ && ln -s ../extlibs/sndfile.framework
	rm $(ASFML).tar.gz

dirbin:
	mkdir -p bin

.PHONY: all clean fclean re

.SILENT: dirbuild dirbin

#Build rule
$(TARGET) : $(OBJ)
	@echo "\n\033[1;4;34mLNK:\033[0m\n"$^"\n\033[36mLinking objects ...\033[0m\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

#Compilation rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT)
	@mkdir -p $(dir $@)
	@echo "\n\033[1;4;34mCMP:\033[0m\n"$<"\n\033[36mCompiling src ...\033[0m"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

-include $(DEP)
