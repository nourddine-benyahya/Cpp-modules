SRC = Zombie.cpp main.cpp newZombie.cpp randomChump.cpp

OBJ = $(SRC:.cpp=.o)

NAME = Zombie

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Zombie.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : re clean fclean all