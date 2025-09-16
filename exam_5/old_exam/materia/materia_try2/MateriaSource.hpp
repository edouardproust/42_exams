#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	AMateria*	_source[4];

	public:

		MateriaSource();
		MateriaSource(MateriaSource const& src);
		virtual ~MateriaSource();
		MateriaSource&	operator=(MateriaSource const& rhs);

		virtual void		learnMateria(AMateria* m);
		virtual AMateria*	createMateria(std::string const& type);
};

#endif
