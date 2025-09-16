#include "MateriaSource.hpp"

MateriaSource::MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		_source[i] = NULL;
	}
}

MateriaSource::~MateriaSource() {
	for (int i = 0; i < 4; ++i) {
		delete _source[i];
	}
}

void MateriaSource::learnMateria(AMateria* m) {
	for (int i = 0; i < 4; ++i) {
		if (_source[i] == NULL) {
			_source[i] = m;
			return;
		}
	}
	delete m;
}

AMateria* MateriaSource::createMateria(std::string const& type) {
	for (int i = 0; i < 4; ++i) {
		if (_source[i] && type == _source[i]->getType()) {
			return (_source[i]->clone());
		}
	}
	return (NULL);
}

