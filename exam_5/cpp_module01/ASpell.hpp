#ifndef A_SPELL_HPP
# define A_SPELL_HPP

# include <string>
# include <iostream>

class ATarget;

class ASpell
{

	std::string	_name;
	std::string	_effects;

	ASpell();
	ASpell&	operator=(ASpell const);

	public:

		// Constructor & Destructor
		ASpell(std::string const& name, std::string const& effects);
		ASpell(ASpell const& src);
		virtual ~ASpell();

		// Accessors
		std::string const&	getName() const;
		std::string const&	getEffects() const;

		// Actions
		virtual ASpell*	clone() const = 0;
		void			launch(ATarget const& target) const;

};

#endif
