#include "Fwoosh.hpp"

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::Fwoosh(Fwoosh const& src): ASpell(src) {}

Fwoosh::~Fwoosh() {}

Fwoosh&	Fwoosh::operator=(Fwoosh const& rhs) {
	if (this != &rhs) {
		ASpell::operator=(rhs);
	}
	return (*this);
}

ASpell*	Fwoosh::clone() const {
	return (new Fwoosh(*this));
}

