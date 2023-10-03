# ifndef	AOPTIONS_REGISTRY_HPP
# define	AOPTIONS_REGISTRY_HPP

#include <string>
#include <vector>

class AOptionsRegistry
{
	public:
		AOptionsRegistry() = default ;
		AOptionsRegistry(const AOptionsRegistry&) = delete;
		virtual ~AOptionsRegistry() = default;
	protected:
		std::vector<std::string>	options;
};

class AddOptionsRegistry
	: public AOptionsRegistry
{
	public:
		AddOptionsRegistry() ;
		AddOptionsRegistry(const AddOptionsRegistry&) = delete;
		~AddOptionsRegistry() = default;
};

class RemoveOptionsRegistry
	: public AOptionsRegistry
{
	public:
		RemoveOptionsRegistry() ;
		RemoveOptionsRegistry(const RemoveOptionsRegistry&) = delete;
		~RemoveOptionsRegistry() = default;
};

class SaveOptionsRegistry
	: public AOptionsRegistry
{
	public:
		SaveOptionsRegistry() ;
		SaveOptionsRegistry(const SaveOptionsRegistry&) = delete;
		~SaveOptionsRegistry() = default;
};

class LoadOptionsRegistry
	: public AOptionsRegistry
{
	public:
		LoadOptionsRegistry() ;
		LoadOptionsRegistry(const LoadOptionsRegistry&) = delete;
		~LoadOptionsRegistry() = default;
};




# endif//	AOPTIONS_REGISTRY_HPP