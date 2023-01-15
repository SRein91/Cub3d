# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/09 15:09:28 by sreinhol          #+#    #+#              #
#    Updated: 2022/01/31 23:07:56 by sreinhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = libft.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c \
ft_memmove.c ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c ft_strrchr.c ft_strncmp.c ft_memchr.c \
ft_memcmp.c ft_strnstr.c ft_atoi.c ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c \
ft_split.c ft_itoa.c ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c \
ft_putdecimal_fd.c ft_decimaltohexup.c ft_decimaltohexlow.c ft_free_array.c ft_atoi_long.c ft_strlen_double.c \
ft_strcmp.c ft_atoi_long_long.c ft_is_plus_minus.c ft_arraylen.c\
ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c ft_nr_spec.c

all: $(NAME)

$(NAME):
	@${CC} $(FLAGS) -c $(SRC)
	@ar -crs $(NAME) $(SRC:.c=.o)

clean:
	@rm -f *.o

fclean: clean
	@rm -f $(NAME)

re: fclean all
