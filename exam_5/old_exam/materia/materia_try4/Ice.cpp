#include "Ice.hpp"

Ice::Ice(): AMateria("ice") {}

Ice::Ice(Ice const& src): AMateria(src) {}

Ice::~Ice() {}

Ice&	Ice::operator=(Ice const& rhs) {
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}
		
Ice*	Ice::clone() const {
	return (new Ice());
}

void	Ice::use(ICharacter& caster, ICharacter& target) {
std::cout << "* " << caster.getName() << " shoots an ice bolt at " << target.getName() << " *" << std::endl;
}

