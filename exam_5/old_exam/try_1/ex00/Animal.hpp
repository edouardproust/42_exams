#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <string>
#include <iostream>

class Animal
{

	protected:

		std::string	_type;

	public:

		Animal();
		Animal(std::string const& type);
		Animal(Animal const& src);
		virtual ~Animal();
		Animal&	operator=(Animal const& rhs);

		std::string const&	getType() const;

		virtual void	makeSound() const;
};

#endif
