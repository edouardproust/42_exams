#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <vector>
# include "ASpell.hpp"

typedef std::vector<ASpell*> Spells;
typedef std::vector<ASpell*>::iterator SpellsIt;
typedef std::vector<ASpell*>::const_iterator SpellsConstIt;

class Warlock
{
	std::string	_name;
	std::string	_title;
	Spells		_spells;

	Warlock();
	Warlock(Warlock const& src);
	Warlock&	operator=(Warlock const& rhs);

	public:

		Warlock(std::string const& name, std::string const& title);
		~Warlock();

		std::string const&	getName() const;
		std::string const&	getTitle() const;
		void	setTitle(std::string const& title);

		void	introduce() const;
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string spellName);
		void	launchSpell(std::string spellName, ATarget const& target) const;
};

#endif
