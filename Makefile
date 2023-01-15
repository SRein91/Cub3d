# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sreinhol <sreinhol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/05 20:07:57 by dtamulis          #+#    #+#              #
#    Updated: 2022/06/21 18:13:54 by sreinhol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
SRC = $(MAINSRC)
LIBFTNAME = libft.a
LIBFTDIR = libft/
LIBFT = $(addprefix $(LIBFTDIR),  $(LIBFTNAME))
OBJ = *.o

MAINSRC = ./src/*.c
FLAGS = -g -Wall -Wextra -Werror
INCLUDE = -I mlx -L mlx -lmlx

NONE='\033[0m'
GREEN='\033[32m'
YELLOW='\033[33m'
GRAY='\033[2;37m'
CURSIVE='\033[3m'

all: $(NAME)

$(NAME): $(OBJ)
	@echo $(CURSIVE)$(GRAY) "     - Making libft..." $(NONE)
	@make -C $(LIBFTDIR)
	@echo $(CURSIVE)$(GRAY) "     - Compiling $(NAME)..." $(NONE)
	@cp ./mlx/libmlx.dylib libmlx.dylib
	@gcc $(FLAGS) $(OBJ) $(LIBFT) $(INCLUDE) -o $(NAME)
	@echo $(GREEN)"- Compiled -"$(NONE)

$(OBJ): $(SRC)
	@echo $(CURSIVE)$(GRAY) "     - Making object files..." $(NONE)
	@gcc $(FLAGS) -c $(SRC)

clean:
	@echo $(CURSIVE)$(GRAY) "     - Removing object files..." $(NONE)
	@rm -rf $(OBJ) 
	@make -C $(LIBFTDIR) clean

fclean: clean
	@echo $(CURSIVE)$(GRAY) "     - Removing $(NAME)..." $(NONE)
	@rm -rf $(NAME) libmlx.dylib
	@make -C $(LIBFTDIR) fclean

re: fclean all
