#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(Warlock const& src) { (void)src; }

Warlock&	Warlock::operator=(Warlock const& rhs) { (void)rhs; return (*this); }

Warlock::Warlock(std::string const& name, std::string const& title):
	_name(name), _title(title)
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock() {
	for (SpellsIt it = _spells.begin(); it != _spells.end(); ++it) {
		delete it->second;
	}
	_spells.clear();
	std::cout << _name << ": My job here is done!" << std::endl;
}

std::string const&	Warlock::getName() const {
	return _name;
}

std::string const&	Warlock::getTitle() const {
	return _title;
}

void	Warlock::setTitle(std::string const& title) {
	_title = title;
}

void	Warlock::introduce() const {
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell) {
	if (spell) {
		_spells[spell->getName()] = spell;
	}
}

void	Warlock::forgetSpell(std::string spellName) {
	SpellsIt it = _spells.find(spellName);
	if (it != _spells.end()) {
		delete it->second;
		_spells.erase(it);
	}
}

void	Warlock::launchSpell(std::string spellName, ATarget const& target) const {	
	SpellsConstIt it = _spells.find(spellName);
	if (it != _spells.end()) {
		it->second->launch(target);
	}
}

