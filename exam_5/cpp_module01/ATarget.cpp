#include "ATarget.hpp"
#include "ASpell.hpp"

// Constructor & Destructor

ATarget::ATarget(std::string const& type)
	: _type(type) {}

ATarget::ATarget(ATarget const& src)
	: _type(src._type) {}

ATarget::~ATarget() {}

// Accessors

std::string const&	ATarget::getType() const
{
	return _type;
}

// Actions

void	ATarget::getHitBySpell(ASpell const& spell) const
{
	std::cout << _type << " has been " << spell.getEffects() << "!" << std::endl;
}

