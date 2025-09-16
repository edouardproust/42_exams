#ifndef MATERIA_SOURCE_HPP
# define MATERIA_SOURCE_HPP

# include "IMateriaSource.hpp"

class MateriaSource: public IMateriaSource
{
	AMateria*	_source[4];

	public:

		MateriaSource();
		MateriaSource(MateriaSource const& src);
		MateriaSource& operator=(MateriaSource const& rhs);
		virtual ~MateriaSource();

		virtual bool		learnMateria(AMateria*);
		virtual AMateria*	createMateria(std::string const & type);
};

#endif
