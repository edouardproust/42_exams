#include "AAnimal.hpp"

AAnimal::AAnimal(std::string const& type): _type(type)
{
	std::cout << "Animal created" << std::endl;
}

AAnimal::AAnimal(AAnimal const& src): _type(src._type)
{
	std::cout << "Animal copied" << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "Animal destroyed" << std::endl;
}

AAnimal&	AAnimal::operator=(AAnimal const& rhs)
{
	if (&rhs != this) {
		_type = rhs._type;
	}
	std::cout << rhs._type << " assigned to " << _type << std::endl;
	return (*this);
}

std::string const&  AAnimal::getType() const
{
	return (_type);
}

