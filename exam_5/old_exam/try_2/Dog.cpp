#include "Dog.hpp"

Dog::Dog(): AAnimal("Dog"), _brain(new Brain())
{
	std::cout << "Dog created" << std::endl;
}

Dog::Dog(Dog const& src): AAnimal(src), _brain(new Brain(*src._brain))
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
	if (&rhs != this) {
		AAnimal::operator=(rhs);
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
