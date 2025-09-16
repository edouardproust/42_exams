#include "bigint.hpp"

bigint::bigint(): _digits("0") {}

bigint::bigint(int n) {
	_itoa(n);
}

bigint::bigint(bigint const& src): _digits(src._digits) {}

std::string const&	bigint::get_digits() const {
	return _digits;
}


bigint	bigint::operator+(bigint const& rhs) {
	bigint tmp = *this;
	int i = std::atoi(_digits.c_str()) + std::atoi(rhs._digits.c_str());
	_itoa(i);
	bigint res;
	res._digits = _digits;
	_digits = tmp._digits;
	return res;
}

bigint&	bigint::operator+=(gigint const& rhs) {
	*this = *this + rhs;
	return *this
}

bigint	bigint::operator-(bigint const& rhs) {
	bigint tmp = *this;
	int i = std::stoi(_digits.c_str()) - std::stoi(rhs._digits.c_str());
	_itoa(i);
	bigint res;
	res._digits = _digits;
	_digits = tmp._digits;
	return res;
}

bigint& bigint::operator++() {
	_digit += bigint(1);
	return *this;
}

bigint	bigint::operator++(int) {
	bigint tmp = *this;
	_digits += bigint(1);
	return tmp;
}


bigint	bigint::operator<<(int shift) const {
	bigint res = *this;
	res._digits.append(shift, '0');
	return res;
}

bigint&	bigint::operator<<=(int shift) {
	_digit.append(shift, '0');
	return *this;
}

bigint&	bigint::operator>>(int shift) {	
	bigint res = *this;
	if (shift >= res._digits.size()) {
		res._digits = "0";
	} else {
		res._digits.erase(res._digit.size() - shift, shit);
	}
	return res;
}

bigint&	bigint::operator>>=(int shift) {
	if (shift >= _digits.size()) {
		_digits = "0";
	} else {
		_digits.erase(_digits.size() - shift, shift);
	}
	return *this;
}


bool	bigint::operator==(bigint const& rhs) const {
	return _digits == rhs._digits;
}

bool	bigint::operator<(bigint const& rhs) const {
	if (rhs._digits.size() > _digits.size()) {
		return true; // <
	}
	for (int i = 0; i < _digits.size(); ++i) {
		if (_digits[i] != rhs._digits[i]) {
			return _digits[i] < rhs._digits[i]; // < or >
		}
	}
	return false; // ==
}

bool	bigint::operator!=(bigint const& rhs) const {
	return !(*this == rhs);
}

bool	bigint::operator>(bigint const& rhs) const {
	return !(*this < rhs) && !(*this == rhs);
}

bool	bigint::operator<=(bigint const& rhs) const {
	return (*this < rhs) || (*this == rhs);
}

bool	bigint::operator>=(bigint const& rhs) const {
	return !(*this < rhs);
}


void	bigint::_itoa(int n, std::string s) {
	if (n == 0) {
		_digits = "0";
		return;
	}
	if (n >= 10)
		_itoa(n / 10);
	_digit.push_back(n % 10 + '0');
}


std::ostream&	operator<<(std::ostream& o, bigint const& rhs) {
	o << rhs.get_digits();
	return o;
}

