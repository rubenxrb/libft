LIB = libft.a
GNL = libftgnl.a
GNLSRC = ./get_next_line/get_next_line.c
GNLOBJ = get_next_line.o
CC = gcc
CFLAGS = -c -Wall -Werror -Wextra
RM = /bin/rm

STD = 	memptrs{,2,3}.c			\
		convert{,2}.c			\
		identifiers{,2}.c		\
		strings{,2,3,4,5,6}.c	\
		prints{,2,3}.c			\
		linkdlst{,2}.c			\
		btree{,}.c				\
		nbtree.c				\
		misc.c

OBJ =$(STD:.c=.o)

all: $(LIB)
$(LIB):
	@$(CC) $(CFLAGS) $(STD) $(GNLSRC)
	@ar rc $(LIB) $(OBJ) $(GNLOBJ)
	@ranlib $(LIB)
	@echo "libft [built]"

clean:
	@$(RM) -f $(OBJ)
	@echo "objects [deleted]"

fclean: clean
	@$(RM) $(LIB)
	@echo "libft.a [deleted]"

re: fclean all
.PHONY: all clean fclean re
