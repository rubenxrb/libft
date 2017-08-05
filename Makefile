NAME = clibft.a
FULL = libft.a

CC = /bin/gcc
RM = /bin/rm
CFLGS = -Wall -Werror -Wextra

ODIR = obj/
SDIR = src/
CDIR = core/
EDIR = extra/
TDIR = structs/
GDIR = $(SDIR)$(EDIR)get_next_line/
CSD = $(addprefix $(SDIR), $(CDIR))
ESD = $(addprefix $(SDIR), $(EDIR))
TSD = $(addprefix $(SDIR), $(TDIR))
GSD = $(addsuffix $(SDIR), $(GDIR))

COD = $(addprefix $(ODIR), $(CDIR))
EOD = $(addprefix $(ODIR), $(EDIR))
TOD = $(addprefix $(ODIR), $(TDIR))
GOD = $(subst $(SDIR),$(ODIR),$(GDIR))

CINC = -Iinc/
GINC = -I$(ESD)get_next_line/inc/

CFLS = convert1 convert2 corelst1 corelst2 identifiers1 memptrs1	\
	memptrs2 prints1 prints2 strings1 strings2 strings3 strings4	\
	strings5 strings6

EFLS = convert3 convert4 identifiers3 memptrs3 misc1 prints3 prints4	\
	strings7 strings8 wchar1 wchar2

TFLS = array1 array2 btree1 btree2 dlst1 dlst2 hash1 lst1 lst2 nbtree1	\
       queue1 stack1 stack2 trie1

CSRC = $(addsuffix .c,  $(addprefix $(CSD), $(CFLS)))
COBJ = $(addsuffix .o,	$(addprefix $(COD), $(CFLS)))

ESRC = $(addsuffix .c,  $(addprefix $(ESD), $(EFLS)))
EOBJ = $(addsuffix .o,	$(addprefix $(EOD), $(EFLS)))

TSRC = $(addsuffix .c,	$(addprefix $(TSD), $(TFLS)))
TOBJ = $(addsuffix .o,	$(addprefix $(TOD), $(TFLS)))

GSRC = $(GSD)get_next_line.c
GOBJ = $(GOD)get_next_line.o

.PHONY: all clean fclean re

all:
	@echo $(GSRC) $(GOBJ)
	@$(MAKE) -j $(NAME) $(FULL)

$(NAME): $(COBJ)
	@ar rc $(NAME) $(COBJ)

$(FULL): $(EOBJ) $(TOBJ) $(GOBJ)
	@ar rc $(FULL) $(NAME) $(EOBJ) $(TOBJ) $(GOBJ)

b_core:
	@mkdir -p $(COD)

b_extra:
	@mkdir -p $(EOD) $(TOD) $(GOD)

$(COD)%.o:$(CSD)%.c | b_core
	$(CC) $(CFLGS) $(CINC) -c $< -o $@

$(EOD)%.o:$(ESD)%.c | b_extra
	$(CC) $(CFLGS) $(CINC) $(GINC) -c $< -o $@

$(GOD)%.o:$(GSD)%.c | $(ESD)get_next_line/
	$(CC) $(CFLGS) $(CINC) $(GINC) -c $< -o $@

$(TOD)%.o:$(TSD)%.c
	$(CC) $(CFLGS) $(CINC) $(GINC) -c $< -o $@

clean:
	$(RM) -rf $(ODIR)

fclean: clean
	$(RM) -rf $(NAME) $(FULL)

re: fclean all
