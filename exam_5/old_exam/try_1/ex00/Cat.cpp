#include "Cat.hpp"

Cat::Cat(): Animal("Cat")
{
	std::cout << "Default Cat created" << std::endl;
}

Cat::Cat(Cat const& src): Animal(src)
{
	std::cout << "Cat copied" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat destroyed" << std::endl;
}

Cat&	Cat::operator=(Cat const& rhs)
{
	if (this != &rhs) {
		this->_type = rhs._type;
	}
	return (*this);
}

void	Cat::makeSound() const
{
	std::cout << "Meowww" << std::endl;
}
