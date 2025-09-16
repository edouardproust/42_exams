#include "SpellBook.hpp"

SpellBook::SpellBook(SpellBook const& src) {
	(void)src;
}

SpellBook&	SpellBook::operator=(SpellBook const& rhs) {
	(void)rhs;
	return (*this);
}

SpellBook::SpellBook() {}

SpellBook::~SpellBook() {
	for (SpellsIt it = _spells.begin(); it != _spells.end(); ++it) {
		delete (*it);
	}
	_spells.clear(); 
}

Spells	SpellBook::getSpells() const {
	return (_spells);
}

void	SpellBook::learnSpell(ASpell* spell) {
	if (spell) {
		_spells.push_back(spell);
	}
}

void	SpellBook::forgetSpell(std::string const& spellName) {
	for (SpellsIt it = _spells.begin(); it != _spells.end(); ++it) {
		if ((*it)->getName() == spellName) {
			delete (*it);
			_spells.erase(it);
		}
	} 
}

ASpell*	SpellBook::createSpell(std::string const& spellName) {
	for (SpellsIt it = _spells.begin(); it != _spells.end(); ++it) {
		if ((*it)->getName() == spellName) {
			return ((*it)->clone());
		}
	} 
	return (NULL);
}

