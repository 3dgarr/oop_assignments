CXX			= c++
NAME		= parser
SRCS		= $(wildcard *.cpp)
OBJS		= $(SRCS:.cpp=.o)
CXXFLAGS	= -Wall -Wextra -Werror -fsanitize=address -g -std=c++17

%.o:%.cpp $(wildcard *.hpp)
	$(CXX) $(CXXFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)
	@echo "$(GREEN)✅ Compiled!$(DEFAULT)"

clean:
	@rm -f *.o
	@echo "$(RED)🧨 Objects are destroyed$(DEFAULT)"

fclean: clean
	@rm -f $(NAME)
	@echo "$(RED)🧨 Executable is destroyed$(DEFAULT)"


re: fclean all

.PHONY: all clean fclean re

#COLORS
RED = \033[1;31m
GREEN = \033[1;32m
YELLOW = \033[1;33m
DEFAULT = \033[0m
#  `shuf -i 1-1000 -n 3000 | tr "\n" " " `