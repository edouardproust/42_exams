#include "Dummy.hpp"

Dummy::Dummy(): ATarget("Target Practice Dummy") {}

Dummy::Dummy(Dummy const& src): ATarget(src) {}

Dummy::~Dummy() {}

Dummy&	Dummy::operator=(Dummy const& rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return (*this);
}

Dummy*	Dummy::clone() const {
	return (new Dummy(*this));
}

