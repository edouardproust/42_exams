#ifndef TARGET_GENERATOR_HPP
# define TARGET_GENERATOR_HPP

# include <string>
# include <vector>
# include "ATarget.hpp"

typedef	std::vector<ATarget*>					Targets;
typedef	std::vector<ATarget*>::iterator			TargetsIt;
typedef	std::vector<ATarget*>::const_iterator	TargetsConstIt;

class TargetGenerator
{
	Targets	_targets;

	TargetGenerator(TargetGenerator const& src);
	TargetGenerator&	operator=(TargetGenerator const& rhs);

	public:

		TargetGenerator();
		~TargetGenerator();

		void		learnTargetType(ATarget* target);
		void		forgetTargetType(std::string const& targetType);
		ATarget*	createTarget(std::string const& targetType);
};

#endif
