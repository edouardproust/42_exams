#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>
# include <map>
# include "ASpell.hpp"

class Warlock
{

	std::string						_name;
	std::string						_title;
	std::map<std::string, ASpell*>	_spells;

	Warlock();
	Warlock(Warlock const&);
	Warlock&	operator=(Warlock const&);

	public:

		// Constructor & Destructor
		Warlock(std::string const& name, std::string const& title);
		~Warlock();

		// Accessors
		std::string const&	getName() const;
		std::string const&	getTitle() const;
		void				setTitle(std::string const& title);

		// Actions
		void	introduce() const;
		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const& spellName);
		void	launchSpell(std::string const& spellName, ATarget const& target) const;

};

#endif
