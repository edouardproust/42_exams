#include "searchable_tree_bag.hpp"

searchable_tree_bag::searchable_tree_bag(): tree_bag() {}

searchable_tree_bag::searchable_tree_bag(searchable_tree_bag const& src):
	tree_bag(src) {}

searchable_tree_bag&	searchable_tree_bag::operator=(searchable_tree_bag const& rhs) {
	if (this != &rhs) {
		tree_bag::operator=(rhs);
	}
	return *this;
}

searchable_tree_bag::~searchable_tree_bag() {}

bool searchable_tree_bag::has(int value) const {
	node* current = tree;
	while (current != nullptr) {
		if (current->value == value) {
			return true;
		}
		if (value < current->value) {
			current = current->l;
		} else {
			current = current->r;
		}
	}
	return false;
}

