#include "Character.hpp"

Character::Character(): _name("character")
{
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
}

Character::Character(std::string const& name): _name(name)
{
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
}

Character::Character(Character const& src): _name(src._name)
{
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = src._inventory[i] ? src._inventory[i]->clone() : NULL;
	}
	for (std::vector<AMateria*>::const_iterator it = src._unequipped.begin();
		it != src._unequipped.end(); ++it) {
		_unequipped.push_back(*it ? (*it)->clone() : NULL);
	}
}

Character::~Character()
{
	for(int i = 0; i < 4; ++i) {
		delete _inventory[i];
	}
	for (std::vector<AMateria*>::iterator it = _unequipped.begin();
		it != _unequipped.end();) {
		delete *it;
		it = _unequipped.erase(it);
	}
}

Character&	Character::operator=(Character const& rhs)
{
	if (this != &rhs) {
		_name = rhs._name;
		for (int i = 0; i < 4; ++i) {
			delete _inventory[i];
			_inventory[i] = rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL;
		}
		for (std::vector<AMateria*>::iterator it = _unequipped.begin();
			it != _unequipped.end();) {
			delete *it;
			it = _unequipped.erase(it);
		}
		for (std::vector<AMateria*>::const_iterator it = rhs._unequipped.begin();
			it != rhs._unequipped.end(); ++it) {
			_unequipped.push_back(*it ? (*it)->clone() : NULL);
		}
	}
	return (*this);
}

std::string const& Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
	_unequipped.push_back(m);
}

void	Character::unequip(int idx)
{
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL) {
		return;
	}
	_unequipped.push_back(_inventory[idx]);
	_inventory[idx] = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= 4 || _inventory[idx] == NULL) {
		return;
	}
	_inventory[idx]->use(target);
}

