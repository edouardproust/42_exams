#include "vect2.hpp"

vect2::vect2(): _x(0), _y(0) {}

vect2::vect2(int x, int y): _x(x), _y(y) {}

vect2::vect2(vect2 const& src): _x(src._x), _y(src._y) {}

vect2::~vect2() {}

vect2&	vect2::operator=(vect2 const& rhs) {
	if (this != &rhs) {
		_x = rhs._x;
		_y = rhs._y;
	}
	return *this;
}

vect2	vect2::operator-() {
	return vect2(-_x, -_y);
}

int&	vect2::operator[](int idx) {
	return (idx == 0) ? _x : _y;
}

int const&	vect2::operator[](int idx) const {
	return (idx == 0) ? _x : _y;	
}
		

vect2&	vect2::operator++() {
	++_x;
	++_y;
	return *this;
}

vect2	vect2::operator++(int) {
	vect2 tmp = *this;
	++_x;
	++_y;
	return tmp;
}

vect2&	vect2::operator--() {
	--_x;
	--_y;
	return *this;
}

vect2	vect2::operator--(int) {
	vect2 tmp = *this;
	--_x;
	--_y;
	return tmp;
}

vect2	vect2::operator+(vect2 const& rhs) const {
	return vect2(_x + rhs._x, _y + rhs._y);
}

vect2	vect2::operator-(vect2 const& rhs) const {
	return vect2(_x - rhs._x, _y - rhs._y);
}

vect2	vect2::operator*(int scalar) const {
	return vect2(_x * scalar, _y * scalar);	
}

vect2&	vect2::operator+=(vect2 const& rhs) {
	_x += rhs._x;
	_y += rhs._y;
	return *this;
}

vect2&	vect2::operator-=(vect2 const& rhs) {
	_x -= rhs._x;
	_y -= rhs._y;
	return *this;
}

vect2&	vect2::operator*=(int scalar) {
	_x *= scalar;
	_y *= scalar;
	return *this;
}

bool	vect2::operator==(vect2 const& rhs) {
	return (_x == rhs._x) && (_y == rhs._y);
}

bool	vect2::operator!=(vect2 const& rhs) {
	return !(*this == rhs);
}

int	vect2::get_x() const {
	return _x;
}

int	vect2::get_y() const {
	return _y;
}

vect2	operator*(int scalar, vect2 const& rhs) {
	return vect2(scalar * rhs.get_x(), scalar * rhs.get_y());
}

std::ostream&	operator<<(std::ostream& o, vect2 const& rhs) {
	o << "{" << rhs.get_x() << ", " << rhs.get_y() <<  "}";
	return o;
}

