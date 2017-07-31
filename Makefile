NAME = libft.a

CC = /bin/gcc
CFLGS = -Wall -Werror -Wextra
RM = /bin/rm

ODIR = ./obj/
SDIR = ./src/
CDIR = ./src/core/
EDIR = ./src/extra/
TDIR = ./src/structs/

IDIR = ./inc/
IGNL = $(EDIR)get_next_line/inc/

CFLS = convert1 corelst1 corelst2 identifiers1 memptrs1 memptrs2	\
		prints1 prints2 strings1 strings2 strings3 strings4			\
		strings5 strings6

EFLS = convert2 convert3 identifiers2 identifiers3 memptrs3 misc1	\
		prints3 prints4 strings7 strings8 wchar1 wchar2

TFLS = array1 array2 btree1 btree2 dlst1 dlst2 hash1 lst1 lst2		\
		nbtree1 queue1 stack1 stack2 trie1

CSRC = $(addsuffix .c,  $(addprefix $(CDIR),$(CFLS)))
ESRC = $(addsuffix .c,  $(addprefix $(EDIR),$(EFLS)))
TSRC = $(addsuffix .c,	$(addprefix $(TDIR),$(TFLS)))

all:
	@$(MAKE) -j $(NAME)
