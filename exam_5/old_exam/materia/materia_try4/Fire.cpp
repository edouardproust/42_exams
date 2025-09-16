#include "Fire.hpp"

Fire::Fire(): AMateria("fire") {}

Fire::Fire(Fire const& src): AMateria(src) {}

Fire::~Fire() {}

Fire&	Fire::operator=(Fire const& rhs) {
	if (this != &rhs) {
		AMateria::operator=(rhs);
	}
	return (*this);
}
		
Fire*	Fire::clone() const {
	return (new Fire());
}

void	Fire::use(ICharacter& caster, ICharacter& target) {
std::cout << "* " << caster.getName() << " shoots a fire ball in " << target.getName() << "'s ass *" << std::endl;
}

