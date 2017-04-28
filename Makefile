LIB = libft.a

CC = gcc
RM = /bin/rm
CFLAGS = -Wall -Werror -Wextra
INC = -Iinc

ODIR = ./obj/
SDIR = ./src/

GNLSRC = $(addprefix $(SDIR),get_next_line/src/)
PFSRC = $(addprefix $(SDIR),ft_printf/src/)
GNLS = get_next_line.c
PFS = ft_printf.c get_var.c helpers.c	\
	conv.c print_var.c read_var.c
PFN = $(addprefix $(PFSRC),$(PFS))
GNLN = $(addprefix $(GNLSRC),$(GNLS))
GNLO = $(addprefix $(ODIR)get_next_line/,$(GNLS:.c=.o))
PFO = $(addprefix $(ODIR)ft_printf/,$(PFS:.c=.o))
SRCN = 	memptrs.c memptrs2.c memptrs3.c	\
	convert.c convert2.c				\
	identifiers.c identifiers2.c		\
	strings.c strings2.c strings3.c		\
	strings4.c strings5.c strings6.c	\
	strings7.c wchar.c					\
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

adds: mkadd $(GNLO) $(PFO)

$(GNLO):$(GNLN)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

$(PFO):$(PFN)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<

mkadd:
	@mkdir -p $(addprefix $(ODIR),get_next_line/)
	@mkdir -p $(addprefix $(ODIR),ft_printf/)

clean:
	@$(RM) -rf $(ODIR)
	@$(RM) -rf $(ADDO)
	@printf "\x1b[36m[./obj/] <removed>\n\x1b[0m"

fclean: clean
	@$(RM) -rf $(LIB)
	@printf "\x1b[31m[./libft.a] <removed>\n\x1b[0m"

re: fclean all
.PHONY: all clean fclean re
