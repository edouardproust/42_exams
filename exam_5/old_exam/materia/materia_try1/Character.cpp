#include "Character.hpp"

Character::Character(): _name("materia")
{
	for (int i = 0; i < 4; ++i) {
		_equipped[i] = nullptr;
	}
}

Character::Character(Character const& src): _name(src._name)
{
	for (int i = 0; i < 4; ++i) {
		_equipped[i] = src._equipped[i];
	}

}

Character::~Character()
{
	for (int i = 0; i < 4; ++i) {
		delete _inventory[i];
	}
}

Character&	Character::operator=(Character const& rhs)
{
	
}

std::string const&	Character::getName() const
{
	return (_name);
}

void	Character::equip(AMateria* m)
{
	if (
}

void	Character::unequip(int idx)
{

}

void	Character::use(int idx, Character& target)
{
	if (0 <= idx && idx < 4) {
		_materias[idx]->use(target);
	}
}

