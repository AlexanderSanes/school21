NAME	=	convert

CXX			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
INCLUDE		=	-I .

HEADERS		=	whatever.hpp

SRC			=	main.cpp

OBJ		=	$(SRC:%.cpp=%.o)

all: $(NAME)

$(OBJDIR)	:
	mkdir $(OBJDIR)

$(NAME)	:	$(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

%.o	:	%.cpp $(HEADERS)
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ)

re: clean all
