NAME		= parser
MODULES		= $(shell cd src && find * -type d)

SDIR		= src/
ODIR		= obj/
INCDIR		= include/
OBJDIR_NAME	= obj/

CXXFLAGS	= -Wall -Wextra -g3 -std=c++17 #-fsanitize=address # -Werror

SRCS		= $(wildcard src/*.cpp)
TEMP		= $(subst $(SDIR),$(ODIR),$(SRCS))
OBJS		= $(SRCS:.cpp=.o)
HEADERS		= $(wildcard $(INCDIR)/*.hpp)

vpath %.cpp $(SRCDIR)

define compile
$1/%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $$< -o $$@
endef

$(foreach dir, $(OBJDIR), $(eval $(call compile, $(dir))))

all: mkdir $(NAME)

mkdir:
	@if [ ! -d "$(OBJDIR_NAME)" ]; then mkdir -p $(OBJDIR) ; fi

$(NAME): $(OBJS)
	$(CXX) $(OBJS) $(CXXFLAGS) -o $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:	fclean all

.PHONY: all clean fclean re mkdir
#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
#  `shuf -i 1-1000 -n 3000 | tr "\n" " " `