NAME = slide

SRCS = main.c

OBJS = $(SRCS:.c=.o)

LIB_D = libft

INCS = -I$(LIB_D)/includes

LIBS = -L$(LIB_D) -lft

all: mylib $(NAME)

mylib:
	make -C $(LIB_D)

$(NAME): $(OBJS)
	gcc -o $@ $^ $(LIBS)

%.o: %.c
	gcc -o $@ -c $< $(INCS)

clean:
	make -C $(LIB_D) clean
	/bin/rm -f $(OBJS)

fclean: clean
	make -C $(LIB_D) fclean
	/bin/rm -f $(NAME)

re: fclean all
