#ifndef FWOOSH_HPP
# define FWOOSH_HPP

# include "ASpell.hpp"

class Fwoosh: public ASpell
{

	public:

		// Constructor & Destructor:
		Fwoosh();
		virtual ~Fwoosh();

		// Actions
		virtual Fwoosh*	clone() const;

};

#endif
