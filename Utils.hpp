# ifndef	UTILS_HPP
# define	UTILS_HPP

# include <vector>
# include <string>

using StrVector = std::vector<std::string>;

const std::string RED = "\033[1;31m";
const std::string GREEN = "\033[1;32m";
const std::string YELLOW = "\033[1;33m";
const std::string DEFAULT = "\033[0m";

enum COMMAND_MODE
{
	NORMAL,
	CREATE,
	RUN
};

struct CommandInfo
{
	std::string			command;
	std::vector<double>	operands;
	COMMAND_MODE		mode;
};

# endif//	UTILS_HPP