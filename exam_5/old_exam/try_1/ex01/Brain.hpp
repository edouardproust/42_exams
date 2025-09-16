#ifndef BRAIN_HPP
# define BRAIN_HPP

#include <string>
#include <iostream>

class Brain
{

	std::string	_ideas[100];

	public:

		Brain();
		Brain(Brain const& src);
		virtual ~Brain();
		Brain&	operator=(Brain const& rhs);

		void				setIdea(int index, std::string const& idea);
		std::string const	getIdea(int index) const;
		void				printIdeas() const;
};

#endif
