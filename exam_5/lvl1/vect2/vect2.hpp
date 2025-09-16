#ifndef VECT2_HPP
#define VECT2_HPP

#include <iostream>

class vect2 {

	int	_x;
	int _y;

	public:

		vect2();
		vect2(int, int);
		vect2(vect2 const&);
		vect2& operator=(vect2 const&);
		~vect2();

		int	get_x() const;
		int	get_y() const;

		vect2	operator-();
		int&	operator[](int);
		int const&	operator[](int) const;
		

		vect2&	operator++();
		vect2	operator++(int);
		vect2&	operator--();
		vect2	operator--(int);

		vect2	operator+(vect2 const&) const;
		vect2	operator-(vect2 const&) const;
		vect2	operator*(int) const;

		vect2&	operator+=(vect2 const&);
		vect2&	operator-=(vect2 const&);
		vect2&	operator*=(int);

		bool	operator==(vect2 const&);
		bool	operator!=(vect2 const&);

};

vect2	operator*(int, vect2 const&);
std::ostream&	operator<<(std::ostream&, vect2 const&);

#endif
