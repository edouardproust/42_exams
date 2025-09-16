#ifndef SPELL_BOOK_HPP
#define SPELL_BOOK_HPP

# include <string>
# include <vector>
# include "ASpell.hpp"

typedef std::vector<ASpell*> Spells;
typedef std::vector<ASpell*>::iterator SpellsIt;
typedef std::vector<ASpell*>::const_iterator SpellsConstIt;

class SpellBook
{
	Spells	_spells;

	SpellBook(SpellBook const& src);
	SpellBook&	operator=(SpellBook const& rhs);

	public:

		SpellBook();
		~SpellBook();

		Spells	getSpells() const;

		void	learnSpell(ASpell* spell);
		void	forgetSpell(std::string const& spellName);
		ASpell*	createSpell(std::string const& spellName);
};

#endif
