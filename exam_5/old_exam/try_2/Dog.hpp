#ifndef DOG_HPP
# define DOG_HPP

#include "AAnimal.hpp"

class Dog: public AAnimal
{
	Brain*	_brain;

	public:

		Dog();
		Dog(Dog const&);
		virtual ~Dog();
		Dog&	operator=(Dog const&);

		virtual Brain*	getBrain();
		virtual void	makeSound() const;
};

#endif
