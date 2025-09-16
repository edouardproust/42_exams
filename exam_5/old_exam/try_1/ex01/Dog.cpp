#include "Dog.hpp"

Dog::Dog(): Animal("Dog"), _brain(new Brain())
{
	std::cout << "Default Dog created" << std::endl;
}

Dog::Dog(Dog const& src): Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Dog copied" << std::endl;
}

Dog::~Dog()
{
	delete _brain;
	std::cout << "Dog destroyed" << std::endl;
}

Dog&	Dog::operator=(Dog const& rhs)
{
	if (this != &rhs) {
		Animal::operator=(rhs);
		this->_type = rhs._type;
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Brain*	Dog::getBrain()
{
	return (_brain);
}

void	Dog::makeSound() const
{
	std::cout << "Woof! Woof!" << std::endl;
}
