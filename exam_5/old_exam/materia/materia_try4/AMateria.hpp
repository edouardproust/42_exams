#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>
# include <iostream>
# include "ICharacter.hpp"

class AMateria
{
	protected:

		std::string	_type;

		AMateria();
		AMateria(std::string const& type);

	public:
		
		AMateria(AMateria const& src);
		virtual ~AMateria();
		AMateria&	operator=(AMateria const& rhs);
		std::string const&	getType() const;
		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& caster, ICharacter& target) = 0;
};

#endif

