#include "Fireball.hpp"

Fireball::Fireball(): ASpell("Fireball", "burnt to a crisp") {}

Fireball::Fireball(Fireball const& src): ASpell(src) {}

Fireball::~Fireball() {}

Fireball&	Fireball::operator=(Fireball const& rhs) {
	if (this != &rhs) {
		ASpell::operator=(rhs);
	}
	return (*this);
}

Fireball*	Fireball::clone() const {
	return (new Fireball(*this));
}

