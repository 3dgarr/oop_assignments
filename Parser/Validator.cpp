#include	"Validator.hpp"

void Validator::tokenize(const std::string& input, std::vector<std::string>& strArguments)
{
	std::stringstream	ss(input);
	if (ss.fail())
		throw	std::runtime_error("SStream failed");
	
	size_t	i = 0;
	std::string	tmp;
	while (std::getline(ss, tmp, ' '))
	{
		strArguments.push_back(tmp);
		++i;
	}	
}

void	Validator::checkIdxOfCmd(const std::string& commnad)
{
	
}

