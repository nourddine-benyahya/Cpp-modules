SRC = HumanA.cpp HumanB.cpp Weapon.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = UViolence

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re  : fclean all

.PHONY : re clean all fclean