#include "AMateria.hpp"

AMateria::AMateria(): _type("materia") {}

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria::AMateria(AMateria const& src)
{
	(void)src;
}

AMateria&	AMateria::operator=(AMateria const& rhs)
{
	(void)rhs;
	return (*this);
}

AMateria::~AMateria() {}

std::string const&	AMateria::getType() const
{
	return (_type);
}

