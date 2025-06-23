#ifndef WARLOCK_HPP
# define WARLOCK_HPP

# include <string>
# include <iostream>

class Warlock
{

	std::string	_name;
	std::string	_title;

	Warlock();
	Warlock(Warlock const& src);
	Warlock&	operator=(Warlock const& rhs);

	public:

		// Constructor & Destructor
		Warlock(std::string const& name, std::string const& title);
		~Warlock();

		// Accessors
		std::string const&	getName() const;
		std::string const&	getTitle() const;
		void				setTitle(std::string const& title);

		// Actions
		void	introduce() const;

};

#endif
