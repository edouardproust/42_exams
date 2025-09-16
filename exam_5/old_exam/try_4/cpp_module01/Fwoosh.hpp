#ifndef FWOOSH_HPP
# define FWOOSH_HPP

#include "ASpell.hpp"

class Fwoosh: public ASpell
{
	public:
		
		Fwoosh();
		Fwoosh(Fwoosh const& src);
		virtual ~Fwoosh();
		Fwoosh&	operator=(Fwoosh const& rhs);

		virtual ASpell*	clone() const;
};

# endif
