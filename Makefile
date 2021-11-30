#======#
#Source#
#======#

SRC = get_next_line.c get_next_line_utils.c main.c

OBJS = ${SRC:.c=.o}

#====#
#Tags#
#====#

AR = ar rc
CFLAGS =  -Wall -Werror -Wextra -D BUFFER_SIZE=${BUFFER_SIZE}
SANIFLAG = -fsanitize=address
NAME = gnl
BUFFER_SIZE = 1

#=========#
#Commandes#
#=========#

.c.o:
			@gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			@gcc -o ${NAME} ${OBJS} ${SANIFLAG}

all:		${NAME}

run:		re
			@./${NAME}

trip:		
			@make -C gnlTester

clean:
			@ rm -f ${OBJS}

fclean:		clean
			@rm -f ${NAME}

re:			fclean all

.PHONY : all run clean fclean re