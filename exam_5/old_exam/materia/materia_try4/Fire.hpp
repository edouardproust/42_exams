#ifndef FIRE_HPP
# define FIRE_HPP

#include "AMateria.hpp"

class Fire: public AMateria
{
	public:
		Fire();
		Fire(Fire const& src);
		virtual	~Fire();
		Fire&	operator=(Fire const& rhs);
		
		virtual Fire*	clone() const;
		virtual void	use(ICharacter& caster, ICharacter& target);
};

#endif

