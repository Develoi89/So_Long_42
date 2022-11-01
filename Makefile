NAME 	= so_long.a

CFLAGS = -Wall -Werror -Wextra

SRCS = 	src/so_long.c \
		src/map.c \
		src/so_long_utils.c \
		src/events.c \

OBJS 	= ${SRCS:.c=.o}



RM 		= rm -f

HEADER	= src/so_long.h

.c.o:	
	make -C libft
	make -C mlx
	gcc -c ${CFLAGS} -Imlx $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${OBJS} ${HEADER}
			ar rc ${NAME} ${OBJS}
			gcc ${CFLAGS} -Lmlx -lmlx -framework OpenGL -framework AppKit libft/libft.a mlx/libmlx.a ${NAME} -o so_long

clean:
			${RM} ${OBJS}
			make clean -C libft
			make clean -C mlx

fclean:		clean
			${RM} ${NAME}
			make fclean -C libft
			rm so_long

re:			fclean all

.PHONY:		all clean fclean re
