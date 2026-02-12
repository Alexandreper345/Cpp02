NAME = Fixed
CPP = c++
FLAGS = -Wall -Wextra -Werror -std=c++98
SRCC = main.cpp Fixed.cpp
OBJ = ${SRCC:.cpp=.o}

all: ${NAME}

${NAME}: ${OBJ}
	${CPP} ${FLAGS} ${OBJ} -o ${NAME}

%.o: %.cpp
	${CPP} ${FLAGS} -c $< -o $@

clean:
	rm -rf ${OBJ}

fclean : clean
	rm -rf ${NAME}

re: fclean all