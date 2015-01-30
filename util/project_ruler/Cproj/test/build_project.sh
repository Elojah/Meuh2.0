#Project creation, default for CPP

#Optionally you can add theses lines in your bashrc
#alias cla='sh util/new_class.sh'
#alias rcla='sh util/remove_class.sh'

#Test name
if test -z "$1"
then
echo "Usage: sh build_project project_name"
else

#------------------------------------------------------------
#Create main dir
mkdir -p $1
cd $1

#Create Sub dir
mkdir -p bin build doc include lib src test util

#------------------------------------------------------------Create Makefile
echo 'TARGET = bin/runner

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

#List interfaces here
INTERFACE =

#Auto var
SRC = $(addsuffix $(SRC_EXT), $(addprefix $(SRC_DIR)/, $(CLASS)))
OBJ = $(addsuffix .o, $(addprefix $(BUILD_DIR)/, $(CLASS)))
DEP = $(addsuffix .h, $(addprefix $(INC_DIR)/, $(CLASS)))
LIBS = $(addprefix -L,$(LIB_DIR))

#Flags
CFLAGS = -MMD -Wall -Wextra -Werror -O3 -g -std=c++98
LFLAGS =

#Libs
LIB_LOCAL =
LIB_GLOBAL =
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
	@echo "\\n\\033[1;4;34mDEP:\\033[0m\\n"$^"\\n\\033[36mLinking objects ...\\033[0m\\n"
	$(CC) $(CFLAGS) $^ -o $@ $(LIBS)

$(BUILD_DIR)/%.o: $(SRC_DIR)/%$(SRC_EXT) $(DEP)
	@echo "\\n\\033[1;4;34mSRC:\\033[0m\\n"$<"\\n\\033[36mCompiling src ...\\033[0m\\n"
	$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(OBJ): $(DEP)
' > Makefile
#------------------------------------------------------------!Create Makefile
#------------------------------------------------------------Create util files
cd util
#New class
echo "if test -z \"\$1\"
then
echo \"Usage: sh util/new_class.sh Class_Name\"
else
echo '#include \"'\$1'.h\"

'\$1'::'\$1'(void)
{
	;
}

'\$1'::~'\$1'(void)
{
	;
}
' > src/\$1.cpp;

echo '#ifndef '\$(echo \"\$1\" | tr \"[:lower:]\" \"[:upper:]\")'_H
# define '\$(echo \"\$1\" | tr \"[:lower:]\" \"[:upper:]\")'_H

class '\$1'
{
public:
	'\$1'(void);
	~'\$1'(void);
protected:
private:
};

#endif
' > include/\$1.h;

echo ''\$1' documentation\n
' > doc/\$1
sed -i '15 i\\	'\$1'\\\\\' Makefile
fi
" > new_class.sh

#Remove class
echo 'if test -z "\$1"
then
echo \"Usage: sh util/remove_class.sh Class_Name\"
else
rm src/$1.cpp
rm include/$1.h
rm doc/$1
sed -i "/$1/d" Makefile

fi
' > remove_class.sh
cd ..
#------------------------------------------------------------!Create util files
#------------------------------------------------------------Create main
echo '#include "main.h"

int	main(int ac, char **av)
{
	;
	ac = ac;
	av = av;
	return (0);
}
' > src/main.cpp
echo '#ifndef MAIN_H
# define MAIN_H

#endif
' > include/main.h
#------------------------------------------------------------!Create main

fi
