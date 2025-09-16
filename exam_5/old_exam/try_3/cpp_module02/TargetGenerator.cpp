#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator(TargetGenerator const& src) {
	(void)src;
}

TargetGenerator&	TargetGenerator::operator=(TargetGenerator const& rhs) {
	(void)rhs;
	return (*this);
}

TargetGenerator::TargetGenerator() {}

TargetGenerator::~TargetGenerator() {
	for (TargetsIt it = _targets.begin(); it != _targets.end(); ++it) {
		delete *it;
	}
	_targets.clear();
}

void	TargetGenerator::learnTargetType(ATarget* target) {
	if (target) {
		_targets.push_back(target->clone());
	}
}

void	TargetGenerator::forgetTargetType(std::string const& targetType) {
	for (TargetsIt it = _targets.begin(); it != _targets.end(); ++it) {
		if (targetType == (*it)->getType()) {
			delete *it;
			_targets.erase(it);
			return;
		}
	}
}

ATarget*	TargetGenerator::createTarget(std::string const& targetType) {
	for (TargetsIt it = _targets.begin(); it != _targets.end(); ++it) {
		if (targetType == (*it)->getType()) {
			return ((*it)->clone());
		}
	}
	return (NULL);
}

