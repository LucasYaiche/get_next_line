#======#
#Source#
#======#

SRC = get_next_line.c get_next_line_utils.c

OBJS = ${SRC:.c=.o}

#====#
#Tags#
#====#

AR = ar rc
CFLAGS =  -Wall -Werror -Wextra -D BUFFER_SIZE=1 
NAME = test

#=========#
#Commandes#
#=========#

.c.o:
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

${NAME}:	${OBJS}
			gcc -o ${NAME} ${OBJS}

all:		${NAME}

run:		
			./test

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY : all run