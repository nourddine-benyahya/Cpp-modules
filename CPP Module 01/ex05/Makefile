SRC = Harl.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CC = c++

FLAGS = -Wall -Wextra -Werror -std=c++98

NAME = Harl

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(FLAGS) $(OBJ) -o $(NAME)

%.o : %.cpp Harl.hpp
	$(CC) $(FLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re  : fclean all

.PHONY : re clean all fclean