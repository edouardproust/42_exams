#include "searchable_array_bag.hpp"

searchable_array_bag::searchable_array_bag(): array_bag() {}

searchable_array_bag::searchable_array_bag(searchable_array_bag const& src):
	array_bag(src) {}

searchable_array_bag&	searchable_array_bag::operator=(searchable_array_bag const& rhs) {
	if (this != &rhs) {
		array_bag::operator=(rhs);
	}
	return *this;
}

searchable_array_bag::~searchable_array_bag() {}

bool searchable_array_bag::has(int value) const {
	for (int i = 0; i < size; ++i) {
		if (value == data[i]) {
			return true;
		}
	}
	return false;
}

