# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrechati <nrechati@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/03/04 17:06:21 by nrechati          #+#    #+#              #
#    Updated: 2019/05/13 15:45:19 by nrechati         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Fractol

LDFLAGS = -L Libft -lft
LIB_DIR = -I includes -I Libft
SRC_PATH = ./srcs/
OBJ_PATH = ./obj/
AUX_DEPS = Libft/libft.h includes/fractol.h
LIB_AUX_DEPS = Libft/libft.a

# *************** SRC **************** #

VPATH = ./srcs

SRC += main.c
SRC += init.c
SRC += menu.c
SRC += trace.c

# *************** OBJ **************** #

OBJ_NAME = $(SRC:.c=.o)
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))

# *************** GCC **************** #

MLX = -I /usr/local/include -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit
CFLAGS = -Wall -Wextra -Werror $(LIB_DIR)
FSANITIZE = -fsanitize=address

GCSUCCES = @echo "\033[33;32m===> Fract'ol Compil\tSUCCESS"
CLSUCCES = @echo "\033[33;31m===> Fract'ol Cleanup\tSUCCESS"
FCLSUCCES = @echo "\033[33;31m===> Fract'ol FCleanup\tSUCCESS"

# *************** MAKE *************** #

all: $(NAME)

$(NAME): $(OBJ) $(LIB_AUX_DEPS)
	@gcc $(OBJ) $(MLX) -o $(NAME) $(LDFLAGS)
	$(GCSUCCES)

Libft/libft.a: Libft Libft/srcs
	@make -C Libft

$(OBJ_PATH)%.o: %.c Makefile $(AUX_DEPS)
	@mkdir -p $(OBJ_PATH)
	@gcc -c $(CFLAGS) -o $@ -c $<

sanitize :
	@gcc $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS) $(FSANITIZE)

debug :
	@gcc -g $(CFLAGS) $(SRC) -o $(NAME) $(LDFLAGS)

clean:
	@rm -rf $(OBJ_PATH)
	@rm -rf Fractol.dSYM
	@make -C Libft fclean
	$(CLSUCCES)

fclean: clean
	@rm -rf $(NAME)
	$(FCLSUCCES)

re: fclean all

.PHONY : all clean fclean re
