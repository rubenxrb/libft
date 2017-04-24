LIB = libft.a

CC = gcc
RM = /bin/rm
CFLAGS = -Wall -Werror -Wextra
INC = -Iinc

ODIR = ./obj/
SDIR = ./src/

ADD = get_next_line/
ADDIR = $(addprefix $(SDIR),$(ADD))
ADDS = $(shell find $(ADDIR) -name '*.c')
ADDO = $(ADDS:.c=.o)
SRCN = 	memptrs.c memptrs2.c memptrs3.c	\
	convert.c convert2.c				\
	identifiers.c identifiers2.c		\
	strings.c strings2.c strings3.c		\
	strings4.c strings5.c strings6.c	\
	strings7.c							\
	prints.c prints2.c prints3.c		\
	linkdlst.c linkdlst2.c				\
	btree.c	nbtree.c misc.c				\
	stack.c stack2.c array.c

OBJN =	$(SRCN:.c=.o)
SRC =	$(addprefix $(SDIR),$(SRCN))
OBJ =	$(addprefix $(ODIR),$(OBJN))
ADDOBJD = $(addprefix $(ODIR),$(ADD))

all: $(LIB)

$(LIB): src adds
	@ar rc $(LIB) $(ADDO)
	@printf "\x1b[32m[./libft.a] <compiled>\n\x1b[0m"

src: mkobj $(OBJ) comp
$(ODIR)%.o:$(SDIR)%.c
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

mkobj:
	@mkdir -p $(ODIR)

comp:
	@ar rc $(LIB) $(OBJ)

adds: $(ADDO)
$(ADDO):$(ADDS)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

clean:
	@$(RM) -rf $(ODIR)
	@$(RM) -rf $(ADDO)
	@printf "\x1b[36m[./obj/] <removed>\n\x1b[0m"

fclean: clean
	@$(RM) -rf $(LIB)
	@printf "\x1b[31m[./libft.a] <removed>\n\x1b[0m"

re: fclean all
.PHONY: all clean fclean re
