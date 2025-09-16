#include "Polymorph.hpp"

Polymorph::Polymorph(): ASpell("Polymorph", "turned into a critter") {}

Polymorph::Polymorph(Polymorph const& src): ASpell(src) {}

Polymorph::~Polymorph() {}

Polymorph&	Polymorph::operator=(Polymorph const& rhs) {
	if (this != &rhs) {
		ASpell::operator=(rhs);
	}
	return (*this);
}

Polymorph*	Polymorph::clone() const {
	return (new Polymorph(*this));
}

