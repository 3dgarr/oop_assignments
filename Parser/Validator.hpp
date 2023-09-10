# ifndef VALIDATIOR_HPP
# define VALIDATIOR_HPP

#include <exception>
#include <string>
#include <sstream>
#include <vector>

class Validator
{
	public:
		void	tokenize(const std::string& input, std::vector<std::string>& strArguments);
		void	checkIdxOfCmd(const std::string& commnad);

		
		Validator();
		~Validator();
		
	private:
};


# endif// VALIDATIOR_HPP