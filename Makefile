SRCS		=	spl.c

OBJS		=	${SRCS:.c=.o}

LIBFT_PATH 	= ./libft

LIBFT	= 	${LIBFT_PATH}/libft.a

EXEC	=		pipex

CC			=	cc

RM			=	rm -f

CFLAGS		=	-Wall -Werror -Wextra -Iinclude

AR          = ar rcs

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o}


${EXEC}: 	${OBJS} ${LIBFT} 
			${CC} ${OBJS} -L${LIBFT_PATH} -lft -o ${EXEC}

${LIBFT}:	
			make -C ${LIBFT_PATH}

all:		${LIBFT} ${EXEC}
			
clean:

			${RM} ${OBJS} ${LIBFT} ${EXEC}

fclean:		clean
			${RM} ${LIBFT} ${EXEC}

re:			fclean all

.PHONY:		all clean fclean re libft pipex

