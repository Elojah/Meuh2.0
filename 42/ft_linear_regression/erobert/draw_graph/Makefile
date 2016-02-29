#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: erobert <erobert@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2013/12/17 17:24:53 by erobert           #+#    #+#              #
#    Updated: 2016/01/06 16:59:45 by erobert          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = draw-graph
FILES = main.ml
SRCS = $(addprefix srcs/, $(FILES))
LIBS = graphics.cma str.cma
CMOS = $(SRCS:srcs/%.ml=objs/%.cmo)
CMXS = $(SRCS:srcs/%.ml=objs/%.cmx)
TMPS = $(SRCS:.ml=.ml~) Makefile~
OCC = ocamlc
OPT = ocamlopt
DEP = ocamldep
OFLAGS = 
LFLAGS = -cclib -lgraphics

.PHONY: all clean objs_dir fclean re

.SILENT: objs_dir

all: objs_dir .depend.input .depend $(NAME)

$(NAME): $(NAME).opt $(NAME).byt
	ln -sf $(NAME).byt $(NAME)

$(NAME).byt: $(CMOS)
	$(OCC) -o $(NAME).byt $(LIBS) $(CMOS)
$(NAME).opt: $(CMXS)
	$(OPT) -o $(NAME).opt $(LIBS:.cma=.cmxa) $(CMXS)

objs/%.cmo : srcs/%.ml
	$(OCC) $(OFLAGS) -o $@ -c $^
objs/%.cmi : srcs/%.ml
	$(OCC) $(OFLAGS) -o $@ -c $^
objs/%.cmx : srcs/%.ml
	$(OPT) $(OFLAGS) -o $@ -c $^

objs_dir:
	mkdir -p objs
	touch .depend

depend: .depend
	$(DEP) $(SRCS) > .depend

clean:
	/bin/rm -f $(CMOS) $(CMXS) $(TMPS)
	/bin/rm -rf objs

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(NAME).opt
	/bin/rm -f $(NAME).byt

re: fclean all

.depend.input: Makefile
	@(ls $(SRCS) $(SRCS:.ml=.mli) 2>/dev/null || true) \
	     >  .depend.new
	@diff .depend.new .depend.input 2>/dev/null 1>/dev/null && \
	    (echo 'unchanged'; rm -f .depend.new) || \
	    (echo 'changed'; mv .depend.new .depend.input)

depend: .depend

.depend:: $(SRCS) .depend.input
	@echo '--Re-building dependencies'
	$(DEP) $(SRCS) $(SRCS:.ml=.mli) > .depend

include .depend
