#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

class Character: public ICharacter
{
	std::string				_name;
	AMateria*				_inventory[4];
	std::vector<AMateria*>	_unequipped;

	Character();

	public:
		Character(std::string const& name);
		Character(Character const& src);
		virtual ~Character();
		Character&	operator=(Character const& rhs);

		virtual std::string const& getName() const;

		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);
};

#endif

