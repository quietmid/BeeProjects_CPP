NAME = ClapTrap

SRC = main.cpp \
	  ClapTrap.cpp

OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re