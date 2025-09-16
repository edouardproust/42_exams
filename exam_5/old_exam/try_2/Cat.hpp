#ifndef CAT_HPP
# define CAT_HPP

#include "AAnimal.hpp"

class Cat: public AAnimal
{	

	Brain*	_brain;

	public:

		Cat();
		Cat(Cat const&);
		virtual ~Cat();
		Cat&	operator=(Cat const&);

		virtual void	makeSound() const;
		virtual	Brain*	getBrain();
};

#endif
