#include "Fwoosh.hpp"

// Constructor & Destructor

Fwoosh::Fwoosh(): ASpell("Fwoosh", "fwooshed") {}

Fwoosh::~Fwoosh() {}

// Action

Fwoosh*	Fwoosh::clone() const
{
	return new Fwoosh(*this);
}

