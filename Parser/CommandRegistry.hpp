# ifndef COMMAND_REGISTRY_HPP
# define COMMAND_REGISTRY_HPP

# include <map>
# include <string>
# include "Commands.hpp"

class CommandRegistry
{
	public:
		CommandRegistry();
		~CommandRegistry();
		Command* operator[](const std::string& target);
		
		bool					existsCommand(const std::string& command) const;
	private:
		std::map<std::string, Command*>	cRegistry;
};

//նույն խնդիրը + 
/*
	create ADD ...
	run ...
*/


# endif //COMMAND_REGISTRY_HPP