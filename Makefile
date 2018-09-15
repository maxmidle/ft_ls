NAME = ft_ls

INCLUDE = ft_ls.h

FLAG = -Wall -Werror -Wextra

SRCS = arg_verif.c ft_is.c ft_ls.c basic_fun.c

OBJS = $(SRCS:.c=.o)

LIB = -L ft_printf -lftprintf

all: $(NAME)

$(NAME): $(SRCS)
	@make -C ft_printf
	gcc $(FLAG) -c $(SRCS)
	gcc $(FLAG) -o $(NAME) $(OBJS) $(LIB)

clean:
	rm -f $(OBJS)
	@make clean -C ft_printf

fclean: clean
	rm -f $(NAME)
	@make fclean -C ft_printf

re: fclean all	
