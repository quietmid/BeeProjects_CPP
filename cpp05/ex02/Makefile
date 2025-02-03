NAME = ex02

SRC = main.cpp \
	  Bureaucrat.cpp \
	  AForm.cpp \
	  ShrubberyCreationForm.cpp \

OBJ = $(SRC:.cpp=.o)
CC = c++
RM = rm -f
CPPFLAGS = -Wall -Wextra -Werror -std=c++11

all: $(NAME)

$(NAME): $(OBJ)
		$(CC) $(CPPFLAGS) $(OBJ) -o $(NAME)

%.o:%.cpp
	c++ $(CPPFLAGS) -c $< -o $@

clean: 
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all clean fclean re