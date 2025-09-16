#ifndef DOG_HPP
# define Dog_HPP

#include "Animal.hpp"

class Dog: public Animal
{

	public:

		Dog();
		Dog(Dog const& src);
		virtual ~Dog();
		Dog&	operator=(Dog const& rhs);

		virtual void	makeSound() const;

};

#endif
