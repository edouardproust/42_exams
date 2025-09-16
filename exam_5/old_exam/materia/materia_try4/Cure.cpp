#include "Cure.hpp"

Cure::Cure(): AMateria("cure") {}

Cure::Cure(Cure const& src): AMateria(src) {}

Cure::~Cure() {}

Cure&	Cure::operator=(Cure const& rhs) {
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}
	
Cure*	Cure::clone() const {
	return (new Cure());
}

void	Cure::use(ICharacter& caster, ICharacter& target) {
	std::cout << "* " << caster.getName() << " heals " << target.getName() << "'s wounds *" << std::endl;
}

