#ifndef A_TARGET_HPP
# define A_TARGET_HPP

# include <string>
# include <iostream>

class ASpell;

class ATarget
{

	std::string	_type;

	ATarget();
	ATarget&	operator=(ATarget const&);

	public:

		// Constructor & Destructor
		ATarget(std::string const& type);
		ATarget(ATarget const& src);
		virtual ~ATarget();

		// Accessors
		std::string const&	getType() const;

		// Actions
		virtual ATarget*	clone() const = 0;
		void				getHitBySpell(ASpell const& spell) const;

};

#endif

