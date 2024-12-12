SRC = sources/AMateria.cpp sources/Cure.cpp sources/Ice.cpp sources/Character.cpp sources/MateriaSource.cpp  main.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -I./includes -std=c++98  #-DDEBUG

CPP = c++

NAME = Game

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) 	$(OBJ) -o $(NAME)

%.o : %.cpp ./includes/AMateria.hpp ./includes/Character.hpp ./includes/Cure.hpp ./includes/ICharacter.hpp ./includes/Ice.hpp ./includes/MateriaSource.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : all clean flcean re
