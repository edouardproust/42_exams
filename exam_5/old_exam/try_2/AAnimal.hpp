#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

#include "Brain.hpp"

class AAnimal
{
	AAnimal();

	protected:

		std::string	_type;

		AAnimal&	operator=(AAnimal const&);
		AAnimal(AAnimal const&);

	public:

		AAnimal(std::string const&);
		virtual ~AAnimal();

		virtual void	makeSound() const = 0;
		std::string const&	getType() const;
		virtual Brain*		getBrain() = 0;
};

#endif
