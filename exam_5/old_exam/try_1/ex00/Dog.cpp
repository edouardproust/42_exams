#include "Dog.hpp"

Dog::Dog(): Animal("Dog")
{
	std::cout << "Default Dog created" << std::endl;
}

Dog::Dog(Dog const& src): Animal(src)
{
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog destroyed" << std::endl;
}

Dog&	Dog::operator=(Dog const& rhs)
{
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
