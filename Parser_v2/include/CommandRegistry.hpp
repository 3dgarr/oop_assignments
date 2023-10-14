# ifndef COMMAND_REGISTRY_HPP
# define COMMAND_REGISTRY_HPP

# include <unordered_map>
# include <string>
# include "Commands.hpp"
# include <memory>


class CommandRegistry
{
	public:
		CommandRegistry();
		~CommandRegistry();
		std::unique_ptr<Command>& operator[](const std::string& target) ;
		void printCommands();
		
		bool	existsCommand(const std::string& command) const;
		
	private:
		std::unordered_map<std::string, std::unique_ptr<Command> >	registry;
};

# endif //COMMAND_REGISTRY_HPP