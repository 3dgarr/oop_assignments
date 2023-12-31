# ifndef APPLICATION_HPP
# define APPLICATION_HPP

# include <iostream>
# include <exception>
# include <vector>

# include "CommandRegistry.hpp"
# include "Slide.hpp"
# include "Validator.hpp"
# include "Utils.hpp"
# include "Director.hpp"

class Application
{
	public:
		int run();
	
	public:
		Application(){};
		~Application(){};
	
	private:
		void getInput();
		void printMsg(const std::string& msg, const std::string& color) const;
		void clearContainers();
		
	private:
		std::string					cmd;
		std::string					input;
		std::vector<std::string>	tokens;
		CommandRegistry				registry;
		// Document					document;
		Director					director;
};


# endif// APPLICATION_HPP