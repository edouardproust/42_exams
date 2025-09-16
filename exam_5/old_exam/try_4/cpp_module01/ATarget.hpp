#ifndef A_TARGET_HPP
# define A_TARGET_HPP

# include <string>
# include <iostream>
# include "ASpell.hpp"

class ATarget
{
	std::string	_type;

	ATarget();

	public:

		ATarget(std::string const& type);
		ATarget(ATarget const& src);
		virtual ~ATarget();
		ATarget&	operator=(ATarget const& rhs);

		std::string const&	getType() const;

		virtual ATarget*	clone() const = 0;
		void				getHitBySpell(ASpell const& spell) const;
};

# endif
