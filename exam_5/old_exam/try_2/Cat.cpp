#include "Cat.hpp"

Cat::Cat(): AAnimal("Cat"), _brain(new Brain())
{
	std::cout << "Cat created" << std::endl;
}

Cat::Cat(Cat const& src): AAnimal(src), _brain(new Brain(*src._brain))
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
	if (&rhs != this) {
		AAnimal::operator=(rhs);
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
	std::cout << "Meowww!" << std::endl;
}

