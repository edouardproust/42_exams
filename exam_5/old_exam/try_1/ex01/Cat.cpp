#include "Cat.hpp"

Cat::Cat(): Animal("Cat"), _brain(new Brain())
{
	std::cout << "Default Cat created" << std::endl;
}

Cat::Cat(Cat const& src): Animal(src), _brain(new Brain(*src._brain))
{
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	delete _brain;
	std::cout << "Cat destroyed" << std::endl;
}

Cat&	Cat::operator=(Cat const& rhs)
{
	if (this != &rhs) {
		Animal::operator=(rhs);
		this->_type = rhs._type;
		delete _brain;
		_brain = new Brain(*rhs._brain);
	}
	return (*this);
}

Brain*	Cat::getBrain()
{
	return (_brain);
}

void	Cat::makeSound() const
{
	std::cout << "Meowww" << std::endl;
}
