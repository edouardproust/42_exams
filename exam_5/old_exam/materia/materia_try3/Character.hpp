#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <set>

class Character: public ICharacter
{
	std::string				_name;
	AMateria*				_inventory[4];
	std::set<AMateria*>	_unequipped;

	Character();

	// Utils
	void	_initInventory();
	void	_cloneInventory(Character const& src);
	void	_cloneUnequipped(Character const& src);
	void	_destroyInventory();
	void	_destroyUnequipped();

	public:

		Character(std::string const& name);
		Character(Character const& src);
		virtual ~Character();
		Character&	operator=(Character const& rhs);

		virtual std::string const&	getName() const;

		virtual void	equip(AMateria* m);
		virtual void 	unequip(int idx);
		virtual void 	use(int idx, ICharacter& target);
};

#endif
