#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <string>
#include <iostream>
#include <cstdlib>

class bigint {
	
	std::string	_digits;

	void	_itoa(int);

	public:

		bigint();
		bigint(int);
		bigint(bigint const&);

		std::string const&	get_digits() const;

		bigint	operator+(bigint const&);
		bigint&	operator+=(bigint const&);
		bigint	operator-(bigint const&);

		bigint&	operator++();
		bigint	operator++(int);

		bigint	operator<<(int) const;
		bigint&	operator<<=(int);
		bigint	operator>>(int);
		bigint&	operator>>=(int);

		bool	operator==(bigint const&) const;
		bool	operator!=(bigint const&) const;
		bool	operator<(bigint const&) const;
		bool	operator>(bigint const&) const;
		bool	operator<=(bigint const&) const;
		bool	operator>=(bigint const&) const;
};

std::ostream&	operator<<(std::ostream&, bigint const&);

#endif
