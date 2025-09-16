#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
	for (int i = 0; i < 4; ++i) {
		_source[i] = NULL;
	}
}

MateriaSource::MateriaSource(MateriaSource const& src)
{
	for (int i = 0; i < 4; ++i) {
		_source[i] = src._source[i] ? src._source[i]->clone() : NULL;
	}
}

MateriaSource& MateriaSource::operator=(MateriaSource const& rhs)
{
	if (this != &rhs) {
		for (int i = 0; i < 4; ++i) {
			delete _source[i];
			_source[i] = rhs._source[i] ? rhs._source[i]->clone() : NULL;
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource()
{
	for (int i = 0; i < 4; ++i) {
		delete _source[i];
	}
}

bool	MateriaSource::learnMateria(AMateria* m)
{
	if (!m) {
		return (true);
	}
	for (int i = 0; i < 4; ++i) {
		if (_source[i] == NULL) {
			_source[i] = m;
			return (true);
		}
	}
	return (false);
}

AMateria*	MateriaSource::createMateria(std::string const& type)
{
	for (int i = 0; i < 4; ++i) {
		if (_source[i] && type == _source[i]->getType()) {
			return (_source[i]->clone());
		}
	}
	return (NULL);
}

