#include "AMateria.hpp"

AMateria::AMateria(): _type ("materia") {}

AMateria::AMateria(AMateria const& src): AMateria()
{
	(void)src;
}

AMateria::~AMateria() {}

AMateria::AMateria(std::string const& type): _type(type) {}

AMateria&	AMateria::operator=(AMateria const& rhs)
{
	(void)rhs;
	return (*this);
}
	
std::string const& AMateria::getType() const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	(void)target;
}

