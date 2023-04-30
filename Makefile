NAME	=	so_long

LIBDIR = ./minilibx-linux

SRCS	=	main.c	\
			ft_init_map.c \
			utils.c \
			utils2.c \
			ft_verif_map.c \
			ft_map_temp.c \
			ft_affi_map.c \
			ft_moove.c \
			ft_keycode.c \

OBJ =	${SRCS:.c=.o}

CC =	cc

CFLAGS	=	-Wall -Wextra -Werror -g

.c.o:
			$(CC) $(CFLAGS) -Iminilibx-linux  -Imlx_linux -c $< -o $(<:.c=.o)

$(NAME): ${OBJ}
		cd ./minilibx-linux && ./configure && $(MAKE)
		$(CC) ${OBJ} -Iminilibx-linux minilibx-linux/libmlx_Linux.a -lXext -lX11 -lm -lz -o $(NAME) 
#-L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
all:	${NAME}

clean:
		rm -f ${OBJ}
		cd ${LIBDIR} && ${MAKE} clean

fclean:	clean
		rm -f ${NAME}
		cd ${LIBDIR} && ${MAKE} clean
		
re:	fclean all

.PHONY: all clean fclean re