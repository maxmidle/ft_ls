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

INCLUDE = libft.h libft_struct.h

FLAG = -Wall -Werror -Wextra

SRCS = ft_print_words_tables.c ft_strplc.c ft_strjoin.c ft_putchar.c \
	ft_strlcat.c ft_atoi.c ft_putchar_fd.c ft_strlen.c ft_bzero.c \
	ft_putendl.c ft_strmap.c ft_isalnum.c ft_putendl_fd.c ft_strmapi.c \
	ft_isalpha.c ft_putnbr.c ft_strncat.c ft_isascii.c ft_strccpy.c\
	ft_putnbr_fd.c ft_strncmp.c ft_isdigit.c ft_putstr.c ft_strclen.c \
	ft_strncpy.c ft_isprint.c ft_putstr_fd.c ft_strnequ.c ft_freetab.c \
	ft_issep.c ft_strcat.c ft_strnew.c ft_itoa.c ft_strchr.c ft_putnstr.c \
	ft_strnstr.c ft_memalloc.c ft_strclr.c ft_strrchr.c \
	ft_memccpy.c ft_strcmp.c ft_strsplit.c ft_memchr.c \
	ft_strcpy.c ft_strstr.c ft_memcmp.c ft_strdel.c ft_strbackconc.c \
	ft_strsub.c ft_memcpy.c ft_strndup.c ft_strdup.c ft_strtrim.c \
	ft_memdel.c ft_strequ.c ft_tolower.c ft_memmove.c ft_strcdup.c \
	ft_striter.c ft_toupper.c ft_memset.c ft_striteri.c ft_upcase.c \
	ft_lstnew.c ft_lstdelone.c ft_lstdel.c ft_lstadd.c ft_lstiter.c \
	ft_lstmap.c ft_strconc.c ft_strnconc.c ft_swap.c ft_strrev.c

OBJET = $(SRCS:.c=.o)

$(NAME): $(SRCS)
	@gcc $(FLAG) -c $(SRCS)
	@ar rc libft.a $(OBJET)
	@ranlib libft.a

all: $(NAME)

clean:
	@rm -f $(OBJET)

fclean: clean
	@rm -f libft.a

re:fclean all

lib: $(NAME) clean
