#ifndef POLYMORPH_HPP
# define POLYMORPH_HPP

# include "ASpell.hpp"

class Polymorph: public ASpell
{
	public:

		Polymorph();
		Polymorph(Polymorph const& src);
		virtual ~Polymorph();
		Polymorph&	operator=(Polymorph const& rhs);

		virtual Polymorph*	clone() const;
};

#endif
