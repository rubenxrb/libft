LIB = libft.a
IHDRS = -Iheaders
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
ODIR = ./objs/
RM = /bin/rm

GNLSRC = ./get_next_line/get_next_line.c

LSRC = 	memptrs{,2,3}.c			\
		convert{,2}.c			\
		identifiers{,2}.c		\
		strings{,2,3,4,5,6}.c	\
		prints{,2,3}.c			\
		linkdlst{,2}.c			\
		btree{,}.c				\
		nbtree.c				\
		misc.c

OSRC = $(LSRC:.c=.o)
OGNL = get_next_line.o

all: $(LIB)

$(LIB):
	@$(CC) $(IHDRS) $(CFLAGS) $(LSRC) $(GNLSRC)
	@ar rc $(LIB) $(OSRC) $(OGNL)
	@ranlib $(LIB)
	@echo "libft [built]"

.c.o:
	@$(CC) $(CFLAGS) $< -o $@

objs: libft gnl

libft:
	@$(CC) $(IHDRS) $(CFLAGS) $(LSRC)

gnl:
	@$(CC) $(IHDRS) $(CFLAGS) $(GNLSRC)

clean:
	@$(RM) -f $(OSRC)
	@$(RM) -f $(OGNL)
	@echo "objects [deleted]"

fclean: clean
	@$(RM) -rf $(LIB)
	@echo "libft.a [deleted]"

re: fclean all
.PHONY: all clean fclean re
