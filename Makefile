#!/bin/bash

LIB = libft.a

#tools
CC = gcc
RM = /bin/rm
CFLAGS = -Wall -Werror -Wextra
INC = -Iinc

#dirs
ODIR = ./obj/
SDIR = ./src/

#add-ons (names)
ADD = get_next_line
#add-ons (dir/name)
ADDIR = $(addprefix $(SDIR),$(ADD))
#add-ons src (names)
ADDS = $(wildcard $(ADDIR)/*.c)
#add-ons src (obj name)
ADDO = $(subst $(SDIR),$(ODIR),$(ADDS:.c=.o))
#add-ons src ()

#source (names)
SRCN = 	memptrs.c memptrs2.c memptrs3.c		\
		convert.c convert2.c				\
		identifiers.c identifiers2.c		\
		strings.c strings2.c strings3.c		\
		strings4.c strings5.c strings6.c	\
		prints.c prints2.c prints3.c		\
		linkdlst.c linkdlst2.c				\
		btree.c	nbtree.c misc.c
#source (obj name)
OBJN =	$(SRCN:.c=.o)
#source (dir/name)
SRC =	$(addprefix $(SDIR),$(SRCN))
#source (objs)
OBJ =	$(addprefix $(ODIR),$(OBJN))

#################################################################

#compile lib
all: $(LIB)

#[./src{ + adds}/*.c] -> [./obj/{+ adds/}*.o] & link ./obj/
$(LIB): src adds
	@ar rc $(LIB) $(OBJ) $(ADDO)
	@echo "libft.a [created]"

#create src obj in ./obj/
src: mkobj $(OBJ)
$(OBJ):$(SRC)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
#create <add-dir> objs in ./obj/<add-dir>/
adds: mkobj mkadds $(ADDO)
$(ADDO):$(ADDS)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

mkobj:
	@mkdir -p $(ODIR)

mkadds:
	@mkdir -p $(addprefix $(ODIR),$(ADD))

#delete ./obj/ dir
clean:
	@$(RM) -rf $(ODIR)
	@echo "objects [deleted]"

#delete ./obj/ & lib.a
fclean: clean
	@$(RM) -rf $(LIB)
	@echo "libft.a [deleted]"

#delete and recompile
re: fclean all
.PHONY: all clean fclean re
