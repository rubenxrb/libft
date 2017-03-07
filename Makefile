NAME = libft.a
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

all: $(NAME)
$(NAME):
	@$(CC) $(CFLAGS) $? $(STD)
	@ar rc $(NAME) $? $(OBJ)
	@ranlib $(NAME)
	@echo "libft [built]"

clean:
	@$(RM) -f $(OBJ)
	@echo "objs [deleted]"

fclean: clean
	@$(RM) $(NAME)
	@echo "binary [deleted]"

re: fclean all
.PHONY: all clean fclean re
