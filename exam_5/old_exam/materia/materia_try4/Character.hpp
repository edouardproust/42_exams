#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"

typedef std::vector<AMateria*> Floor;
typedef std::vector<AMateria*>::iterator FloorIt;
typedef std::vector<AMateria*>::const_iterator FloorConstIt;

class Character: public ICharacter
{
	std::string			_name;
	AMateria*			_inventory[4];
	Floor				_floor;

	Character();
	void	_initInventory();
	void	_cloneInventory(Character const& src);
	void	_cloneFloor(Character const& src);
	void	_deleteInventory();
	void	_deleteFloor();

	public:
		Character(std::string const& name);
		Character(Character const& src);
		Character& operator=(const Character& rhs);
		virtual ~Character();

		virtual std::string const&	getName() const;
		virtual AMateria*			get(int idx) const;

		virtual void	equip(AMateria* m);
		virtual void	unequip(int idx);
		virtual void	use(int idx, ICharacter& target);
};

#endif

