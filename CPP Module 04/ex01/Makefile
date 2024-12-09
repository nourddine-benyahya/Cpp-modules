SRC = sources/Animal.cpp sources/Dog.cpp sources/Cat.cpp sources/Brain.cpp  main.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -I./includes -std=c++98

CPP = c++

NAME = Animal

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) 	$(OBJ) -o $(NAME)

%.o : %.cpp ./includes/Animal.hpp ./includes/Cat.hpp ./includes/Dog.hpp 
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : all clean flcean re
