# ifndef COMMAND_HPP
# define COMMAND_HPP

class Command
{
	public:
		Command();
		
		virtual	void execute()  = 0;
		virtual ~Command();

	private:
	
};





# endif //COMMAND_HPP