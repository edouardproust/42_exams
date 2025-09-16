#include "Warlock.hpp"

Warlock::Warlock() {}

Warlock::Warlock(std::string const& name, std::string const& title):
	_name(name), _title(title), _spellBook(new SpellBook) {
	std::cout << _name << ": This looks like another boring day."
		<< std::endl;
}

Warlock::Warlock(Warlock const& src) {
	(void) src;
}

Warlock::~Warlock() {
	for (SpellsIt it = _spells.begin(); it != _spells.end(); ++it) {
		delete *it;
	}
	_spells.clear();
	delete _spellBook;
	std::cout << _name << ": My job here is done!" << std::endl;
}

Warlock&	Warlock::operator=(Warlock const& rhs) {
	(void)rhs; return (*this);
}

std::string const&	Warlock::getName() const {
	return (_name);
}

std::string const&	Warlock::getTitle() const {
	return (_title);
}

void	Warlock::setTitle(std::string const& title) {
	_title = title;
}

void	Warlock::introduce() const {
	std::cout << _name << ": I am " << _name
		<< ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell) {
	if (!spell) {
		return;
	}
	for (SpellsIt it = _spellBook->getSpells().begin(); it != _spellBook->getSpells().end(); ++it) {
		if ((*it)->getName() == spell->getName()) {
			_spells.push_back(spell->clone());
		}
	}
}

void	Warlock::forgetSpell(std::string spellName) {
	for (SpellsIt it = _spellBook->getSpells().begin(); it != _spellBook->getSpells().end(); ++it) {
		if ((*it)->getName() == spellName) {
			delete *it;
			_spells.erase(it);
			return;
		}
	}
}

void	Warlock::launchSpell(std::string spellName, ATarget const& target) {
	learnSpell(_spellBook->createSpell(spellName));
	for (SpellsConstIt it = _spells.begin(); it != _spells.end(); ++it) {
		if ((*it)->getName() == spellName) {
			(*it)->launch(target);
		}
	}
}
