#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class Character: public ICharacter
{
	std::string	_name;
	AMateria*	_equipped[4];

	public:

		Character();
		Character(Character const& src);
		virtual ~Character();
		Character&	operator=(Character const& rhs);

		virtual std::string const&	getName() const;
		virtual void				equip(AMateria* m);
		virtual void				unequip(int idx);
		virtual void				use(int idx, Character& target);
};

#endif

