SRC = Fixed.cpp main.cpp

OBJ = $(SRC:.cpp=.o)

CPPFLAGS = -Wall -Wextra -Werror -std=c++98

CPP = c++

NAME = Fixed

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPPFLAGS) 	$(OBJ) -o $(NAME)

%.o : %.cpp Fixed.hpp
	$(CPP) $(CPPFLAGS) -c $< -o $@

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : all clean flcean re $(NAME)
