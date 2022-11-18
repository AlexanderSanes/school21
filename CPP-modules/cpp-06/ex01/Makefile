NAME	=	Serialization

CXX			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
INCLUDE		=	-I include

SRC			=	main.cpp

OBJ		=	$(SRC:%.cpp=%.o)

all: $(NAME)

$(OBJDIR)	:
	mkdir $(OBJDIR)

$(NAME)	:	$(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

%.o	:	%.cpp
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ)

re: clean all
