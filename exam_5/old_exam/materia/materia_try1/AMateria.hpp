#ifndef A_MATERIA_HPP
# define A_MATERIA_HPP

# include <string>
# include <iostream>

class AMateria
{
	protected:

		std::string	_type;
		AMateria();
		AMateria(AMateria const& src);
		AMateria&	operator=(AMateria const& rhs);
	
	public:

		AMateria(std::string const& type);
		virtual ~AMateria();
		
		std::string const& getType() const;

		virtual AMateria*	clone() const = 0;
		virtual void		use(ICharacter& target);
};

#endif
