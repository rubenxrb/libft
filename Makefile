NAME = corelib.a
GNLC = coregnl.a
LIBFT = libft.a

CC = /bin/gcc
CFLGS = -Wall -Werror -Wextra
RM = /bin/rm

ODIR = ./obj/
SDIR = ./src/
IDIR = ./inc/

#	ALL MAIN DIRS
SCTD = $(addprefix $(SDIR),structures/)
MEMD = $(addprefix $(SDIR),memory/)
CNVD = $(addprefix $(SDIR),conversions/)
HLPD = $(addprefix $(SDIR),helpers/)
PRTD = $(addprefix $(SDIR),prints/)
STRD = $(addprefix $(SDIR),strings/)
RDND = $(addprefix $(SDIR),reading/)
GNLD = $(addprefix $(RDND),get_next_line/src/)
DIRS = $(SCTD) $(MEMD) $(CNVD) $(HLPD) $(PRTD) $(STRD) $(RDND) $(GNLD)

#	ALL STRUCTURE DIRS
S_ARR = $(addprefix $(SCTD),darray/)
S_HTB = $(addprefix $(SCTD),hashtbl/)
S_LST = $(addprefix $(SCTD),list/)
S_QUE = $(addprefix $(SCTD),queue/)
S_SCK = $(addprefix $(SCTD),stack/)
S_TRS = $(addprefix $(SCTD),trees/)
S_DIR = $(S_ARR) $(S_HTB) $(S_LST) $(S_QUE) $(S_SCK) $(S_TRS)

#	ALL HEADER FILES
GINC = $(addprefix $(GINC),get_next_line.h)
CINC = $(addprefix $(IDIR),core.h)
SINC = $(addprefix $(IDIR),structs.h)
LINC = $(addprefix $(IDIR),libft.h)

S_CORE = $(MEMD)memptrs1.c $(MEMD)memptrs2.c $(CNVD)convert1.c			\
	 $(HLPD)identifiers1.c $(STRD)strings1.c $(STRD)strings2.c		\
	 $(STRD)strings3.c $(STRD)strings4.c $(STRD)strings5.c $(STRD)strings6.c\
	 $(PRTD)prints1.c $(PRTD)prints2.c $(addprefix $(S_LST),corelst1.c)	\
	 $(addprefix $(S_LST),corelst2.c)
O_CORE = $(subst ./src/,./obj/,$(S_CORE:.c=.o))

#	ALL COREGNL SOURCE CODE
S_GNL = $(S_CORE) $(GNLD)get_next_line.c
O_GNL = $(subst ./src/,./obj/,$(S_GNL:.c=.o))

#	ALL LIBFT SOURCE CODE
STRCT = $(addprefix $(S_ARR),array1.c) $(addprefix $(S_ARR),array2.c)		\
	$(addprefix $(S_HTB),hash1.c) $(addprefix $(S_LST),dlst1.c)		\
	$(addprefix $(S_LST),dlst2.c) $(addprefix $(S_LST),lst1.c)		\
	$(addprefix $(S_LST),lst2.c) $(addprefix $(S_QUE),queue1.c)		\
	$(addprefix $(S_SCK),stack1.c) $(addprefix $(S_SCK),stack2.c)		\
	$(addprefix $(S_TRS),btree1.c) $(addprefix $(S_TRS),btree2.c)		\
	$(addprefix $(S_TRS),nbtree1.c) $(addprefix $(S_TRS),trie1.c)

S_LIB = $(S_GNL) $(MEMD)memptrs3.c $(CNVD)convert2.c $(CNVD)convert3.c 		\
	$(HLPD)identifiers2.c $(HLPD)identifiers3.c $(HLPD)misc1.c 		\
	$(STRD)strings7.c $(STRD)strings8.c $(STRD)wchar1.c $(STRD)wchar2.c	\
	$(PRTD)prints3.c $(PRTD)prints4.c $(STRCT)
O_LIB = $(subst ./src/,./obj/,$(S_LIB:.c=.o))

all: $(NAME) $(GNLC) $(LIBFT)

build_core:
	@mkdir -p $(addprefix $(ODIR),structures/list/)				\
	$(addprefix $(ODIR),memory) $(addprefix $(ODIR),conversions)		\
	$(addprefix $(ODIR),helpers) $(addprefix $(ODIR),prints)		\
	$(addprefix $(ODIR),strings)

build_coregnl: build_core
	@mkdir -p $(subst ./src/,./obj/,$(GNLD))
	
build_libft: build_coregnl
	@mkdir -p $(subst ./src/,./obj/,$(S_DIR))

$(O_CORE):$(S_CORE) | $(CINC) build_core
	$(CC) $(CFLGS) $(CINC) $< -o $@

$(NAME): $(O_CORE)
	@printf 'BUILDING CORE\n'
	@ls -fl $(S_CORE)
	@echo $(O_CORE)
	@printf 'CORE BUILT\n'

gnl:
	@printf 'BUILDING COREGNL\n'
	@ls -f -l $(S_GNL)
	@echo $(O_GNL)
	@printf 'BUILDING COREGNL\n'

libft:
	@printf 'BUILDING LIBFT\n'
	@ls -f -l $(S_LIB)
	@echo $(O_LIB)
	@printf 'BUILDING LIBFT\n'
clean:
	@$(RM) -rf ./obj/
	@printf 'CLEANING OBJ\n'

fclean: clean
	@$(RM) -f $(NAME) $(GNLC) $(LIBFT)
	@printf 'CLEANING OBJ/BINS\n'

re: fclean all
	@printf 'RE-COMPILING\n'

.PHONY: all clean fclean re
