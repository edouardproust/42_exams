#include "Dummy.hpp"

// Constructor & Destructor

Dummy::Dummy():
	ATarget("Target Practice Dummy") {}

Dummy::~Dummy() {}

// Actions

Dummy*	Dummy::clone() const
{
	return new Dummy(*this);
}

