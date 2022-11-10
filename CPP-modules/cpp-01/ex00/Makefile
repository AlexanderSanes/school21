NAME	=	zombie

CXX			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
INCLUDE		=	-I include

SRCDIR		=	src
OBJDIR		=	obj
HEADERS		=	include/Zombie.hpp

SRC		=	main.cpp Zombie.cpp newZombie.cpp newChump.cpp
OBJ		=	$(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)	:
	mkdir $(OBJDIR)

$(NAME)	:	$(OBJDIR) $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o	:	$(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ)
	rmdir $(OBJDIR)

re: clean all
