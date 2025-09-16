#include "AMateria.hpp"

AMateria::AMateria(): _type("materia") {}

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria::AMateria(AMateria const& src): _type(src._type) {}

AMateria::~AMateria() {}

AMateria&	AMateria::operator=(AMateria const& rhs) {
	(void)rhs;
	return (*this);
}
		
std::string const&	AMateria::getType() const {
	return (_type);
}

