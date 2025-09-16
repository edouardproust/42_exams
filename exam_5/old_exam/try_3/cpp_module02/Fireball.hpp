#ifndef FIREBALL_HPP
# define FIREBALL_HPP

# include "ASpell.hpp"

class Fireball: public ASpell
{
	public:

		Fireball();
		Fireball(Fireball const& src);
		virtual ~Fireball();
		Fireball&	operator=(Fireball const& rhs);

		virtual Fireball*	clone() const;
};

#endif
