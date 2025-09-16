#include "BrickWall.hpp"

BrickWall::BrickWall(): ATarget("Inconspicuous Red-brick Wall") {}

BrickWall::BrickWall(BrickWall const& src): ATarget(src) {}

BrickWall::~BrickWall() {}

BrickWall&	BrickWall::operator=(BrickWall const& rhs) {
	if (this != &rhs) {
		_type = rhs._type;
	}
	return (*this);
}

BrickWall*	BrickWall::clone() const {
	return (new BrickWall(*this));
}

