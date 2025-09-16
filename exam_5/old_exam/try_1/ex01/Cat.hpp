#ifndef CAT_HPP
# define CAT_HPP

#include "Animal.hpp"

class Cat: public Animal
{

	Brain*	_brain;

	public:

		Cat();
		Cat(Cat const& src);
		virtual ~Cat();
		Cat&	operator=(Cat const& rhs);

		virtual Brain*	getBrain();

		virtual void	makeSound() const;

};

#endif
