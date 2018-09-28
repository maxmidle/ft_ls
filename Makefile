NAME = ft_ls

INCLUDE = ft_ls.h

FLAG = -Wall -Werror -Wextra

SRCS = arg_verif.c ft_is.c ft_ls.c basic_fun.c sort1.c sort2.c swap1.c swap2.c \
	swap3.c	large_print.c date_print.c perm_print.c name_print.c \
	minmaj_print.c acl_print.c

OBJS = $(SRCS:.c=.o)

LIB = -L libft -lft

all: $(NAME)

$(NAME): $(SRCS)
	@make -C libft
	gcc $(FLAG) -c $(SRCS)
	gcc $(FLAG) -o $(NAME) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)
	@make clean -C libft

fclean: clean
	rm -f $(NAME)
	@make fclean -C libft

re: fclean all	
