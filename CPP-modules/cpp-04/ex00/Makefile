NAME	=	animal

CXX			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
INCLUDE		=	-I include

SRCDIR		=	src
OBJDIR		=	obj
HEADERS		=	include/Cat.hpp include/Animal.hpp include/Dog.hpp \
				include/WrongAnimal.hpp include/WrongCat.hpp

SRC		=	main.cpp Animal.cpp Cat.cpp Dog.cpp \
			WrongAnimal.cpp WrongCat.cpp

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
