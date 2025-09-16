#include "Animal.hpp"

Animal::Animal(): _type("Animal")
{
	std::cout << "Default Animal created" << std::endl;
}

Animal::Animal(std::string const& type): _type(type)
{
	std::cout << "Animal created" << std::endl;
}

Animal::Animal(Animal const& src): _type(src._type)
{
	std::cout << "Animal copied" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal destroyed" << std::endl;
}

Animal&	Animal::operator=(Animal const& rhs)
{
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

std::string const&	Animal::getType() const
{
	return (_type);
}

