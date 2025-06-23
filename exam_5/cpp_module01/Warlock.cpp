#include "Warlock.hpp"

// Constructor & Destructor

Warlock::Warlock(std::string const& name, std::string const& title)
	: _name(name), _title(title), _spells() // _spells() is optional
{
	std::cout << _name << ": This looks like another boring day." << std::endl;
}

Warlock::~Warlock()
{
	for (std::map<std::string, ASpell*>::iterator it = _spells.begin(); it != _spells.end(); ++it) {
		delete it->second;
	}
	_spells.clear();
	std::cout << _name << ": My job here is done!" << std::endl;
}

// Accessors

std::string const&	Warlock::getName() const
{
	return _name;
}

std::string const&	Warlock::getTitle() const
{
	return _title;
}

void	Warlock::setTitle(std::string const& title)
{
	_title = title;
}

// Actions

void	Warlock::introduce() const
{
	std::cout << _name << ": I am " << _name << ", " << _title << "!" << std::endl;
}

void	Warlock::learnSpell(ASpell* spell)
{
	if (spell && _spells.find(spell->getName()) == _spells.end()) {
		_spells[spell->getName()] = spell->clone();
	}
}

void	Warlock::forgetSpell(std::string const& spellName)
{
	std::map<std::string, ASpell*>::iterator it = _spells.find(spellName);
	if (it != _spells.end()) {
		delete it->second;
		_spells.erase(it);
	}
}

void	Warlock::launchSpell(std::string const& spellName, ATarget const& target) const
{
	std::map<std::string, ASpell*>::const_iterator it = _spells.find(spellName);
	if (it != _spells.end()) {
		it->second->launch(target);
	}	
}

