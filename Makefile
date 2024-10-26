SRCS		=	spl.c

OBJS		=	${SRCS:.c=.o}

LIBFT_PATH 	= ./libft

LIBFT	= 	${LIBFT_PATH}/libft.a

NAME	=		pipex

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra -Iinclude

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


${NAME}: 	${OBJS} ${LIBFT} 
			${CC} ${OBJS} -L ${LIBFT_PATH} -lft -o ${NAME}

			
${LIBFT}:	
			make -C ${LIBFT_PATH}

all:		${LIBFT} ${NAME}
			
clean:
			${RM} ${OBJS} ${LIBFT} ${NAME}
			make -C ${LIBFT_PATH} clean

fclean:		clean
			${RM} ${LIBFT} ${NAME}
			make -C ${LIBFT_PATH} fclean

re:			fclean all

.PHONY:		all clean fclean re