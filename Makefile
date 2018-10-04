NAME = ft_ls

INCLUDE = ft_ls.h

FLAG = -Wall -Werror -Wextra

SORT = sort/sort1.c sort/sort2.c sort/swap1.c sort/swap2.c sort/swap3.c

SRCS = arg_verif.c error.c ft_ls.c basic_fun.c large_print.c date_print.c \
	perm_print.c name_print.c minmaj_print.c acl_print.c

OBJS = $(SRCS:.c=.o) sort1.o sort2.o swap1.o swap2.o swap3.o

LIB = -L libft -lft

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft
	gcc $(FLAG) -c $(SRCS) $(SORT)
	gcc $(FLAG) -o $(NAME) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all	
