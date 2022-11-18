NAME	=	convert

CXX			=	c++
CFLAGS		=	-Wall -Werror -Wextra -std=c++98
INCLUDE		=	-I include

SRCDIR		=	src
OBJDIR		=	obj
HEADERS		=	include/Converter.hpp

SRC			=	main.cpp Converter.cpp 

OBJ		=	$(SRC:%.cpp=$(OBJDIR)/%.o)

all: $(NAME)

$(OBJDIR)	:
	mkdir $(OBJDIR)

$(NAME)	:	$(OBJDIR) $(OBJ)
	$(CXX) $(CFLAGS) $(OBJ) -o $@

$(OBJDIR)/%.o	:	$(SRCDIR)/%.cpp $(HEADERS)
	$(CXX) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	rm -f $(NAME) $(OBJ)
	rmdir $(OBJDIR)

re: clean all
