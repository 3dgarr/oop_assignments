NAME		= application
MODULES		= $(shell cd src && find * -type d)

SDIR		= src/
INCDIR		= include/
OBJDIR		= obj/

CXXFLAGS	= -Wall -Wextra -Werror -g3 -std=c++17 -I $(INCDIR)  -fsanitize=address 

SRCS		= $(wildcard src/*.cpp)
TEMP		= $(SRCS:.cpp=.o)
OBJS		= $(subst $(SDIR), $(OBJDIR), $(TEMP))
HEADERS		= $(wildcard $(INCDIR)/*.hpp)

vpath %.cpp $(SDIR)

obj/%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: mkdir $(NAME)

mkdir:
	@mkdir -p $(OBJDIR)

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
	rm -rf $(OBJDIR)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re mkdir

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
