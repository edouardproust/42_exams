#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{
	std::string	_ideas[100];

	public:

		Brain();
		Brain(Brain const&);
		Brain&	operator=(Brain const&);
		virtual ~Brain();

		void	setIdea(int, std::string const&);
		void	printIdeas() const;
};

#endif
