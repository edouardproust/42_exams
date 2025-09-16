#ifndef I_CHARACTER_HPP
# define I_CHARACTER_HPP

# include <string>
# include <iostream>
# include <vector>

class AMateria; // forward declaration (break circular dependency)

class ICharacter
{
	public:

		virtual ~ICharacter() {}

		virtual std::string const& getName() const = 0;

		virtual void	equip(AMateria* m) = 0;
		virtual void	unequip(int idx) = 0;
		virtual void	use(int idx, ICharacter& target) = 0;
};

#endif

