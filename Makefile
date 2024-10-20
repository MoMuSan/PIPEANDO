SRCS		=	spl.c

OBJS		=	${SRCS:.c=.o}

LIBFT_PATH 	= ./libft

LIBFT	= 	${LIBFT_PATH}/libft.a

EXEC	=		pipex

NAME 		=	libft.a

CC			=	gcc

AR			=	 ar rcs

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra -Iinclude

.c.o:
			${CC} ${CFLAGS} -C $< -o ${<:.c=.o}

${NAME}:	${OBJS}  ${LIBFT} 
			cp ${LIBFT} ${NAME}
			${AR} ${NAME}  ${OBJS}

${EXEC}: 	${OBJS}

${LIBFT}:	
			make -C ${LIBFT_PATH}

all:		${NAME} ${LIBFT} ${EXEC}
			
clean:

			${RM} ${OBJS} ${LIBFT} ${EXEC}

fclean:		clean
			${RM} ${NAME} ${LIBFT} ${EXEC}

re:			fclean all

.PHONY:		all clean fclean re libft pipex

