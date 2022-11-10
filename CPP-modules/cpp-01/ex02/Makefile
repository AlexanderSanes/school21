NAME	=	ex02

CXX		=	c++
CXXFLAGS	=	-Wall -Werror -Wextra -std=c++98
SRC		=	main.cpp
OBJ		=	main.o

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CXX) $(CXXFLAGS) $^ -o $@

%.o	:	%.c
	$(CXX) $(CXXFLAGS) $< -o $@

clean	:
	rm -f $(NAME) $(OBJ)

re	:	clean all