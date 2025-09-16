#include "set.hpp"
#include <cstddef>

set::set(searchable_bag& b): bag(b) {}

set::set(set const& s) : bag(s.bag) {}

set& set::operator=(set const& rhs) {
    if (this != &rhs) {
        bag = rhs.bag;
    }
    return *this;
}

void	set::insert (int value) {
	if (!has(value)) {
		bag.insert(value);
	}
}

void	set::insert (int *values, int size) {
	for (int i = 0; i < size; ++i) {
		insert(values[i]);
	}
}

void	set::print() const {
	bag.print();
}

void	set::clear() {
	bag.clear();
}

bool	set::has(int value) {
	return bag.has(value);
}

searchable_bag&	set::get_bag() const {
	return bag;
}

