SRC = Account.cpp tests.cpp

OBJ = $(SRC:cpp=.o)

NAME = Account

CC = cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME)

%.c : %.o
	$(CC) $(CFLAGS) -c $@ -o $<

clean :
	rm -fr $(OBJ)

fclean : clean
	rm -fr $(NAME)

re : fclean all

.PHONY : all clean fclean re