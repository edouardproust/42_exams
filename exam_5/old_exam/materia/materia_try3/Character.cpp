#include "Character.hpp"

Character::Character(): _name("Anonymous")
{
	_initInventory();
}

Character::Character(std::string const& name): _name(name)
{
	_initInventory();
}

Character::Character(Character const& src): _name(src._name)
{
	_cloneInventory(src);
	_cloneUnequipped(src);
}

Character::~Character()
{
	_destroyInventory();
	_destroyUnequipped();
}

Character&	Character::operator=(Character const& rhs)
{
	if (this != &rhs) {
		_name = rhs._name;
		_destroyInventory();
		_destroyUnequipped();
		_cloneInventory(rhs);
		_cloneUnequipped(rhs);
	}
	return (*this);
}

std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m) {
		return;
	}
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] == m) { // materia already equipped
			return;
		}
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
}

void 	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL) {
		return;
	}
	_unequipped.insert(_inventory[idx]);
	_inventory[idx] = NULL;
}

void 	Character::use(int idx, ICharacter& target)
{ 
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL) {
		return;
	}
	_inventory[idx]->use(target);
}

// Utils

void    Character::_initInventory()
{
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
}

void    Character::_cloneInventory(Character const& src)
{
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = src._inventory[i] ? src._inventory[i]->clone() : NULL;
	}
}

void    Character::_cloneUnequipped(Character const& src)
{
	for (std::set<AMateria*>::const_iterator it = src._unequipped.begin();
		it != src._unequipped.end(); ++it) {
		_unequipped.insert((*it)->clone());
	}
}

void    Character::_destroyInventory()
{
	for (int i = 0; i < 4; ++i) {
		delete _inventory[i];
	}
}

void    Character::_destroyUnequipped()
{
	for (std::set<AMateria*>::iterator it = _unequipped.begin();
		it != _unequipped.end(); ++it) {
		delete *it;
	}
	_unequipped.clear();
}

