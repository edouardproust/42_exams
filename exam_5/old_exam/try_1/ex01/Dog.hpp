#ifndef DOG_HPP
# define DOG_HPP

#include "Animal.hpp"

class Dog: public Animal
{

	Brain*	_brain;

	public:

		Dog();
		Dog(Dog const& src);
		virtual ~Dog();
		Dog&	operator=(Dog const& rhs);

		virtual Brain*	getBrain();

		virtual void	makeSound() const;

};

#endif
