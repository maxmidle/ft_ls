# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: radler <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/11/16 18:33:34 by radler            #+#    #+#              #
#    Updated: 2018/06/21 21:20:27 by radler           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

INCLUDE = ft_printf.h

FLAG = -Wall -Werror -Wextra

SRCS = argform.c argtype1.c argtype2.c argtype3.c argtype4.c ft_itoa_base.c \
	ft_printf.c handleflag.c hashtag.c minsize.c precision.c spaceplus.c \
	zero.c ft_is.c

OBJET = $(SRCS:.c=.o)

$(NAME): $(SRCS)
	@make lib -C libft
	@mv libft/libft.a ./$(NAME)
	@gcc $(FLAG) -c $(SRCS)
	@ar rc $(NAME) $(OBJET)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJET)

fclean: clean
	@rm -f $(NAME)

re:fclean all

lib: $(NAME) clean
