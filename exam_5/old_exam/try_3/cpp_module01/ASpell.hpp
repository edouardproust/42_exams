#ifndef A_SPELL_HPP
# define A_SPELL_HPP

# include <string>
# include "ATarget.hpp"

class ASpell
{
	ASpell();

	protected:

		std::string	_name;
		std::string	_effects;

	public:

		ASpell(std::string const& name, std::string const& effects);
		ASpell(ASpell const& src);
		virtual ~ASpell();
		ASpell&	operator=(ASpell const& rhs);

		std::string const&	getName() const;
		std::string const&	getEffects() const;

		virtual ASpell*	clone() const = 0;
		void	launch(ATarget const& target) const;
};

#endif
