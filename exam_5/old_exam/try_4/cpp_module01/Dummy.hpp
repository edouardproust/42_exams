#ifndef DUMMY_HPP
# define DUMMY_HPP

# include "ATarget.hpp"

class Dummy: public ATarget
{
	public:
		
		Dummy();
		Dummy(Dummy const& src);
		virtual ~Dummy();
		Dummy&	operator=(Dummy const& rhs);

		virtual ATarget*	clone() const;
};

# endif
