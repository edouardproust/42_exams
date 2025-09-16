#include "Character.hpp"

Character::Character(): _name("Anonymous") {
	_initInventory();
}

Character::Character(std::string const& name): _name(name) {
	_initInventory();
}

Character::Character(Character const& src): _name(src._name) {
	_cloneInventory(src);
	_cloneFloor(src);
}

Character& Character::operator=(const Character& rhs) {
	if (this != &rhs) {
		_name = rhs._name;
		_deleteInventory();
		_cloneInventory(rhs);
		_deleteFloor();
		_cloneFloor(rhs);
	}
	return (*this);
}

Character::~Character() {
	_deleteInventory();
	_deleteFloor();
}

std::string const& Character::getName() const {
	return (_name);		
}

AMateria*	Character::get(int idx) const {
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
		return (_inventory[idx]);
	}
	return (NULL);
}

void Character::equip(AMateria* m) {
	if (!m)
		return;
	for (int i = 0; i < 4; ++i) {
		if (_inventory[i] == NULL) {
			_inventory[i] = m;
			return;
		}
	}
	_floor.push_back(m);
}

void Character::unequip(int idx) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
		_floor.push_back(_inventory[idx]);
		_inventory[idx] = NULL;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (idx >= 0 && idx < 4 && _inventory[idx] != NULL) {
		_inventory[idx]->use(*this, target);
	}
}

void	Character::_initInventory() {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = NULL;
	}
}

void	Character::_cloneInventory(Character const& src) {
	for (int i = 0; i < 4; ++i) {
		_inventory[i] = src._inventory[i] ? src._inventory[i]->clone() : NULL;
	}
}

void	Character::_cloneFloor(Character const& src) {
	_deleteFloor();
	for (FloorConstIt it = src._floor.begin(); it != src._floor.end(); ++it) {
		_floor.push_back(*it ? (*it)->clone() : NULL);
	} 
}

void	Character::_deleteInventory() {
	for (int i = 0; i < 4; ++i) {
		delete _inventory[i];
	}
}

void    Character::_deleteFloor() {
	for (FloorIt it = _floor.begin(); it != _floor.end(); ++it) {
		delete *it;
	}
	_floor.clear();
}

