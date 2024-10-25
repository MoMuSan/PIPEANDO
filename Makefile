SRCS		=	spl.c

OBJS		=	${SRCS:.c=.o}

LIBFT_PATH 	= ./libft

LIBFT	= 	${LIBFT_PATH}/libft.a

NAME	=		pipex

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra 

AR          = 	ar rcs

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


${NAME}: 	${OBJS} ${LIBFT} 
			${CC} ${OBJS} -L ${LIBFT_PATH} -lft -o ${NAME}

			
${LIBFT}:	
			make -C ${LIBFT_PATH}

all:		${LIBFT} ${NAME}
			
clean:

			${RM} ${OBJS} ${LIBFT} ${NAME}

fclean:		clean
			${RM} ${LIBFT} ${NAME}

re:			fclean all

.PHONY:		all clean fclean re