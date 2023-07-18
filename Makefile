# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jrinna <jrinna@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/14 12:04:25 by jrinna            #+#    #+#              #
#    Updated: 2023/07/18 11:42:32 by jrinna           ###   ########lyon.fr    #
#                                                                              #
# **************************************************************************** #

-include Source.mk LSource.mk

CC = gcc

CFLAGS = -Wall -Wextra -Werror

NAME = so_long

INC = ./include/so_long.h

INCM = ./mlx_linux

OBJ = $(SRC:.c=.o)

LIBH = ./libft/libft.h

LIBP = ./libft/libft.a

MLXP = ./mlx_linux/libmlx_linux.a

FRAM = -Lmlx_linux -lmlx_Linux -Imlx_linux -lXext -lX11 -lm -lz#-framework OpenGL -framework AppKit

${NAME}: $(LIBP) ${OBJ} Makefile mlx
	$(CC) $(CFLAGS) $(OBJ) -I$(INC) $(FRAM) $(LIBP) -o $(NAME)

$(LIBP): $(LIBH) $(LSRC)
	$(MAKE) -C ./libft

%.o : %.c $(INC)
	$(CC) $(CFLAG) -Imlx_linux -O3 -c $< -o $@

mlx :
	@$(MAKE) -C ./mlx_linux

all : ${NAME}

clean :
	${MAKE} clean -C ./libft
	$(MAKE) clean -C ./mlx_linux
	$(RM) ${OBJ}

fclean : clean
	$(RM) $(LIBP)
	$(RM) $(NAME)

re :
	$(MAKE) fclean
	$(MAKE) all

gmk:
	echo "SRC += " > Source.mk
	echo "LSRC += " > LSource.mk
	find source -name "*.c" | sed 's/^/SRC += /' >> Source.mk
	find libft -name "*.c" | sed 's/^/LSRC += /' >> LSource.mk

nono:
	norminette -R CheckForbiddenSourceHeader
	norminette -R CheckDefined

.PHONY : nono gmk re fclean clean all mlx